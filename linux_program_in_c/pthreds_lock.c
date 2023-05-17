#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock; // declare a mutex lock

void *critical_section(void *arg)
{
    // acquire the lock
    pthread_mutex_lock(&lock);

    // perform the critical section
    printf("In critical section\n");

    // release the lock
    pthread_mutex_unlock(&lock);
}

int main()
{
    pthread_t t1, t2;

    // initialize the lock
    pthread_mutex_init(&lock, NULL);

    // create threads
    pthread_create(&t1, NULL, critical_section, NULL);
    pthread_create(&t2, NULL, critical_section, NULL);

    // join threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // destroy the lock
    pthread_mutex_destroy(&lock);

    return 0;
}
