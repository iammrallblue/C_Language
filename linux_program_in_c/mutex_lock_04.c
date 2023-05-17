#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

int counter = 0;

// pthread_mutex_t is a struct
pthread_mutex_t lock;

void *increment(void *thread_id)
{
    long tid = (long)thread_id; // get thread id

    printf("thread %ld is starting...\n", tid);
    pthread_mutex_lock(&lock); // acquire the mutex lock
    printf("thread %ld has acquired the lock...\n", tid);

    counter++;
    ; // increment the shared counter

    printf("thread %ld incremented the counter to %d ...\n", tid, counter);

    pthread_mutex_unlock(&lock); // release the mutex lock

    printf("thread %ld has released the lock...\n", tid);
    pthread_exit(NULL);

} // increment

int main(int argc, char const *argv[])
{
    pthread_t thd[NUM_THREADS];
    int rc;
    long t;

    // initialize the mutex lock
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("mutex initialization failed.\n");
        exit(1);
    }

    // create the threads
    for (t = 0; t < NUM_THREADS; t++)
    {
        rc = pthread_create(&thd[t], NULL, increment, (void *)t);
        if (rc)
        {
            printf("error: unable to create thread %ld\n", t);
            exit(1);
        }
    }

    // wait for the threads to finish
    for (t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(thd[t], NULL);
    }

    // destroy the mutex lock
    pthread_mutex_destroy(&lock);
    printf("final counter value: %d\n", counter);
    pthread_exit(NULL);

    return 0;
} // main
