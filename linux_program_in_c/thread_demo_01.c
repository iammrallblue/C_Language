#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id)
{
    long tid = (long)thread_id;
    printf("Hello from thread %ld\n", tid);
    pthread_exit(NULL);

} // print_hello

int main(int argc, char const *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    int t;

    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
        if (rc)
        {
            printf("error creating thread %ld\n", t);
            exit(-1);
        }
    }
    pthread_exit(NULL);

    return 0;
} // main
