#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s1, s2;

void *p1(void *arg)
{
    sem_wait(&s1);
    sleep(1);
    sem_wait(&s2);
    printf("p1\n");
    sem_post(&s2);
    sem_post(&s1);
    return NULL;
}

void *p2(void *arg)
{
    sem_wait(&s2);
    sleep(1);
    sem_wait(&s1);
    printf("p2\n");
    sem_post(&s1);
    sem_post(&s2);
    return NULL;
}

int main()
{
    sem_open("s1", O_CREAT, 0666, 1);
    sem_open("s2", O_CREAT, 0666, 1);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, p1, NULL);
    pthread_create(&t2, NULL, p2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_close(&s1);
    sem_close(&s2);
    return 0;
}
