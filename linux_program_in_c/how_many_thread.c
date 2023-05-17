#include <stdio.h>
#include <pthread.h>

void *thread_start(void *arg)
{
    printf("I am a new thread\n");
    pthread_exit(NULL);

} // thread_start

int main(int argc, char const *argv[])
{
    pthread_t tid[4];

    for (int i = 0; i < 4; i++)
    {
        if (pthread_create(&tid[i], NULL, &thread_start, NULL) != 0)
        {
            fprintf(stderr, "Error create thread %d.\n", i);
            return 1;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (pthread_join(tid[i], NULL) != 0)
        {
            fprintf(stderr, "Error joining thread %d.\n", i);
            return 1;
        }
    }

    printf("All threads have completed.\n");

    // pthread_create(&tid[0], NULL, &thread_start, NULL);
    // pthread_create(&tid[1], NULL, &thread_start, NULL);
    // pthread_create(&tid[2], NULL, &thread_start, NULL);
    // pthread_create(&tid[3], NULL, &thread_start, NULL);

    return 0;

} // main