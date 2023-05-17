#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem1, sem2; // declare two semaphores

void *thread_1(void *arg)
{

    sem_wait(&sem1); // waiting semaphore 1
    printf("Thread 1 acquired sem1\n");

    sleep(1);

    sem_wait(&sem2); //  waiting semaphore 2
    printf("Thread 1 acquired sem2\n");

    sem_post(&sem2); // release semaphore 2
    sem_post(&sem1); // release semaphore 1

    return NULL;

} // thread_1()

void *thread_2(void *arg)
{

    sem_wait(&sem2); // wait for semaphore sem2 to be available
    printf("Thread 2 acquired sem2\n");

    sleep(1);

    sem_wait(&sem1);
    printf("Thread 2a acquired sem1\n");

    sem_post(&sem1);
    sem_post(&sem2);

    return NULL;
} // thread_2()

int main()
{
    pthread_t t1, t2;

    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 1);

    pthread_create(&t1, NULL, thread_1, NULL);
    pthread_create(&t2, NULL, thread_2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);

    return 0;
}
