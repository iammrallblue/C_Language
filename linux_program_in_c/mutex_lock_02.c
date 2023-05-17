#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5

pthread_mutex_t lock;
int counter = 0;

void *thread_func(void *arg)
{
    int i;
    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
} // thread_func()

int main(int argc, char const *argv[])
{
    pthread_t threads[THREAD_COUNT];
    int i;

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_create(&threads[i], NULL, thread_func, NULL);
        printf("created thread %d\n", i);
    }

    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
        printf("joined thread %d\n", i);
    }

    pthread_mutex_destroy(&lock);

    printf("counter value: %d\n", counter);

    return 0;
}
