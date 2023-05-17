#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variable that all threads have access to
int counter = 0;

// Declare and initialize mutex lock
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Function that each thread will run
void *worker(void *arg)
{
    int i;

    // Enter critical section by acquiring lock
    pthread_mutex_lock(&lock);

    // Increment counter 1,000,000 times
    for (i = 0; i < 1000000; i++)
    {
        counter++;
    }

    // Exit critical section by releasing lock
    pthread_mutex_unlock(&lock);

    // Exit thread
    pthread_exit(NULL);
}

int main()
{
    int i;

    // Declare array of 10 threads
    pthread_t threads[10];

    // Create 10 threads
    for (i = 0; i < 10; i++)
    {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    // Wait for all threads to finish
    for (i = 0; i < 10; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Print final value of counter
    printf("Counter value: %d\n", counter);

    return 0;
}
