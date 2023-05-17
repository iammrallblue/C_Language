#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <pthread.h>

#define THREAD_COUNT 5

// global atomic variable, a macro
atomic_int counter = ATOMIC_VAR_INIT(0);

// function declarations
void increment(atomic_int *v);
int compare_and_swap(atomic_int *v, int expected, int new_value);

void *thread_func(void *arg)
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        increment(&counter);
    }

    return NULL;
} // thread_func()

/* this increment() function will go infinite loop */
// void increment(atomic_int *v)
// {
//     int temp;
//     do
//     {
//         temp = *v;
//         printf("temp = %d\n", temp);
//         printf("compare_and_swap = %d\n", compare_and_swap(v, temp, temp + 1));
//     } while (temp != compare_and_swap(v, temp, temp + 1));

// } // increment()

/* to fix the infinite loop issue*/
void increment(atomic_int *v)
{
    int expected, new_value;
    do
    {
        expected = *v;
        new_value = expected + 1;
    } while (!atomic_compare_exchange_strong(v, &expected, new_value));
} // increment()

int main(int argc, char const *argv[])
{
    pthread_t threads[THREAD_COUNT];
    int i;
    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_create(&threads[i], NULL, thread_func, NULL);
        printf("Created thread %d\n", i);
    }
    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Joined thread %d\n", i);
    }
    printf("Counter value: %d\n", counter);

    return 0;
} // main

// implementation of compare_and_swap() function
int compare_and_swap(atomic_int *v, int expected, int new_value)
{
    return atomic_compare_exchange_strong(v, &expected, new_value);
}
