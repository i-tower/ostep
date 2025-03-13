#ifndef WISHPATHS_H
#define WISHPATHS_H

#include <stdlib.h>
#include <strings.h>
#include "argparse.h"

#define MAX_PATH 4096

StringList* init_path(void)
{
    StringList* new_strlist = malloc(sizeof(StringList));
    new_strlist->list = malloc(sizeof(char*) * 16);
    if (new_strlist == NULL || new_strlist->list == NULL) {
        fprintf(stderr, "malloc failed to allocate memory for path\n");
        exit(1);
    }

    new_strlist->len = 0;
    new_strlist->size = 16;
    
    push_stringlist(new_strlist, "/bin/");

    return new_strlist;
}

void push_path(StringList* sl, StringArena* a, char* path) 
{
    char* allocd_path = string_alloc(a, path, strlen(path) + 1);

    push_stringlist(sl, allocd_path);
}

void destroy_path(StringList* sl)
{
    free(sl->list);
    free(sl);
}


int resolve_path(const StringList* paths, char* path_buffer, const char* command) 
{
    for (size_t i = 0; i < paths->len; ++i) {
        // Check if the file exists in the paths available
        snprintf(path_buffer, MAX_PATH, "%s%s", paths->list[i], command);
        if (!access(path_buffer, F_OK)) {
            return 1;
        }
    }

    return 0;
}

#endif