#include <stdio.h>
#include <string.h>
#include <sys/sem.h>
#include <semaphore.h>
#include "shared_memory.h"

#define NUM_ITERATIONS 10

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("usage - %s //no args", argv[0]);
        return -1;
    }

    // setup some semaphores
    sem_unlink(SEM_CONSUMER_FNAME);
    sem_unlink(SEM_PRODUCER_FNAME);

    sem_t *sem_prod = sem_open(SEM_PRODUCER_FNAME, 0);
    if (sem_prod == SEM_FAILED)
    {
        perror("sem_open/producer");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_cons = sem_open(SEM_CONSUMER_FNAME, 0);
    if (sem_cons == SEM_FAILED)
    {
        perror("sem_open/consumer");
        exit(EXIT_FAILURE);
    }

    // grab the shared memory block
    char *block = attach_memory_block(FILENAME, BLOCK_SIZE);
    if (block == NULL)
    {
        printf("ERROR: couldn't get block\n");
        return -1;
    }

    for (int i = 0; i < NUM_ITERATIONS; i++)
    {
        sem_wait(sem_cons); // wait for the consumer to have an open slot.
        printf("Writing: \"%s\"\n", argv[1]);
        strncpy(block, argv[1], BLOCK_SIZE);
        sem_post(sem_prod); // signal that something has been produced.
    }

    sem_close(sem_prod);
    sem_close(sem_cons);
    detach_memory_block(block);
    return 0;
}

// https://youtu.be/ukM_zzrIeXs