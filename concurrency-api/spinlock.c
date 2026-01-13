#include <stdio.h>

int lock_acquire(int* lock) {
    while (*lock);
   *lock = 1;
  return 1;
}

int lock_release(int* lock) {
    *lock = 0;
    return 0;
}

struct someval {
    int lock;
    int value;
};

int main(void)
{
    struct someval lockedval = {
        .lock = 0,
        .value = 225,
    };

    printf("Locked value before %d\n", lockedval.value);

    lock_acquire(&lockedval.lock);
    lockedval.value = 0;
    lock_release(&lockedval.lock);

    printf("Locked value after %d\n", lockedval.value);

    return 0;
}
