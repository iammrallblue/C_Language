#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

// global variable lock
bool lock = false;

bool test_and_set(bool *target)
{
    bool rv = *target;
    *target = true;
    return rv;
} // test_and_set()

// process function to use test_and_set()
void process(int id)
{

    printf("process %d is doing some work.\n", id);

    while (test_and_set(&lock))
    {
        printf("process %d is waiting for the lock.\n", id);
    }

    // enter critical section
    printf("process %d has acquired the lock.\n", id);

    // operating inside of critical section
    printf("process %d is doing some critical work.\n", id);

    printf("process %d has released the lock.\n", id);

    lock = false;
}

int main(int argc, char const *argv[])
{

    for (int i = 0; i < 3; i++)
    {
        process(i);
    }

    return 0;
}
