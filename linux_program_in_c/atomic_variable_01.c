#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>

atomic_int count = 0;

void *thread_function(void *arg)
{
    for (int i = 0; i < 10000; i++)
    {
        atomic_fetch_add(&count, 1);
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final Value of count: %d\n", count);

    return 0;

} // main
