#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

volatile int lock = 0;

int test_and_set(volatile int *target)
{
    int rv = *target;
    *target = 1;
    return rv;
}

void *process(void *id)
{
    int thread_id = *(int *)id;

    printf("thread %d is doing some work.\n", thread_id);

    while (test_and_set(&lock) != 0)
    {
        printf("thread %d is waiting for the lock.\n", thread_id);
    }

    printf("thread %d has acquired the lock.\n", thread_id);

    printf("thread %d is doing some critical work.\n", thread_id);

    printf("thread %d has released the lock.\n", thread_id);

    lock = 0;

    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i;

        if (pthread_create(&threads[i], NULL, process, (void *)&thread_args[i]))
        {
            fprintf(stderr, "error creating thread\n");

            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
