#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2
#define NUM_ITEMS 10

sem_t *mutex, *empty, *full;
int buffer[BUFFER_SIZE];

int in = 0, out = 0;

void *producer(void *arg)
{
    int i;
    for (i = 0; i < NUM_ITEMS; i++)
    {
        sem_wait(empty); // check the buffer size for adding a new item
        sem_wait(mutex); // check if other process is using the buffer

        // produce item, then add to buffer
        int item = rand() % 100;
        printf("producing item %d\n", item);
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        sem_post(mutex); // release the buffer for other process
        sem_post(full);  // update the buffer size, if adding a new item is successful
    }

    return NULL;
} // producer()

void *consumer(void *arg)
{

    int i;
    for (i = 0; i < NUM_ITEMS; i++)
    {
        sem_wait(full);  // check if there is any item to consume
        sem_wait(mutex); // check if other process is using the buffer, if yes, wait

        // remove item (consume item)
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("consumed item %d\n", item);

        sem_post(mutex); // release the buffer for next process
        sem_post(empty); // update the buffer size, if removing an item is successful
    }

    return NULL;
} // consumer()

int main(int argc, char const *argv[])
{
    pthread_t p_producer[NUM_PRODUCERS];
    pthread_t p_consumer[NUM_CONSUMERS];
    int i;

    /*
        semaphores mutex, empty, and full need to be initialized
        mutex = 1;
        full = 0;
        empty = n; n is the buffer size (BUFFER_SIZE)
    */
    mutex = sem_open("mutex", 0, 1);
    empty = sem_open("empty", 0, BUFFER_SIZE);
    full = sem_open("full", 0, 0);

    /* up to 2 producers */
    /* up to 2 consumers */
    for (i = 0; i < NUM_PRODUCERS; i++)
    {
        pthread_create(&p_producer[i], NULL, &producer, NULL);
        pthread_create(&p_consumer[i], NULL, &consumer, NULL);
    }

    // there is a synchronizing relationship between producer and consumer

    for (i = 0; i < NUM_PRODUCERS; i++)
    {
        pthread_join(p_producer[i], NULL);
        pthread_join(p_consumer[i], NULL);
    }

    sem_close(mutex);
    sem_close(empty);
    sem_close(full);

    sem_unlink("mutex");
    sem_unlink("empty");
    sem_unlink("full");

    return 0;
} // main
