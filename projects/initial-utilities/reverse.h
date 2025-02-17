#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
typedef struct String_Stack {
    char** arr;
    size_t top;
    size_t size; 
} String_Stack;

typedef struct Arena {
    char* arena_buffer;
    size_t buffer_size;
    size_t current_offset;
    size_t prev_offset;

} Arena;




void stack_init(String_Stack* stack, size_t size) 
{
    stack->top = 0;
    stack->size = size;
    stack->arr = (char**) malloc(sizeof(char*) * size); 
    assert(stack->arr != NULL);
}

void push_stack(String_Stack* stack, char* string_ptr) 
{ 
    assert(stack->top + 1 <= stack->size);
    stack->arr[stack->top] = string_ptr;
    stack->top++;
}

char* pop_stack(String_Stack* stack) 
{
    stack->top--;
    return stack->arr[stack->top];
}

void stack_deinit(String_Stack* stack) 
{
    free(stack->arr); 
}

void* arena_alloc(Arena* arena, size_t size)
{ 
    if (arena->current_offset + size <= arena->buffer_size){
        void* ptr = &arena->arena_buffer[arena->current_offset];
        arena->prev_offset = arena->current_offset;
        arena->current_offset += size;
        memset(ptr, 0, size);
        return ptr;
    }

    return NULL;
}

void arena_init(Arena* arena, void* backing_buffer, size_t buff_size){
    arena->arena_buffer = (char*) backing_buffer;
    arena->buffer_size = buff_size;
    arena->current_offset = 0;
    arena->prev_offset = 0;
    
}

ssize_t get_filesize(char* filename)
{
    struct stat st;
    assert(stat(filename, &st) != -1);
    return st.st_size;
}
