#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 2
#define NUM_READS 10
#define NUM_WRITES 5

sem_t *mutex, *rw_mutex;
int read_count = 0, data_set = 0;

void *reader(void *arg)
{
    int i;
    for (i = 0; i < NUM_READS; i++)
    {
        sem_wait(mutex); // check if other process in use the read_count, if not read_count++
        read_count++;    // new reader arrived
        if (read_count == 1)
        {
            sem_wait(rw_mutex); // reader in reading, writer has to wait
        }
        sem_post(mutex); // release read_count after finished increment

        printf("read %ld read data as %d\n", (long)arg, data_set);

        sem_wait(mutex); // check if other process in use the read_count, if not read_count++
        read_count--;    // reader left after finish reading
        if (read_count == 0)
        {
            sem_post(rw_mutex); // release read_count, writer can write
        }
        sem_post(mutex); // release read_count, after read left
    }

    return NULL;

} // reader()

void *writer(void *arg)
{

    int i;
    for (i = 0; i < NUM_WRITES; i++)
    {
        sem_wait(rw_mutex); // check if
        data_set++;
        printf("writer %ld wrote data as %d\n", (long)arg, data_set);
        sem_post(rw_mutex);
    }

    return NULL;

} // writer()

int main(int argc, char const *argv[])
{
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    long i;

    mutex = sem_open("/mutex", 0644, 1);
    rw_mutex = sem_open("/rw_mutex", 0644, 1);

    for (i = 0; i < NUM_READERS; i++)
    {
        pthread_create(&readers[i], NULL, &reader, (void *)i);
    }

    for (i = 0; i < NUM_WRITERS; i++)
    {
        pthread_create(&writers[i], NULL, &writer, (void *)i);
    }

    for (i = 0; i < NUM_READERS; i++)
    {
        pthread_join(readers[i], NULL);
    }

    for (i = 0; i < NUM_WRITERS; i++)
    {
        pthread_join(writers[i], NULL);
    }

    sem_close(mutex);
    sem_close(rw_mutex);

    sem_unlink("/mutex");
    sem_unlink("rw_mutex");

    return 0;
} // main
