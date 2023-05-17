#include <stdio.h>
#include <pthread.h>

/*
This is a C program that demonstrates the use of a mutex lock
to solve the critical section problem. The program initializes
a shared variable named "counter" to 0 and a mutex lock named "lock".

Two threads are created and execute the "thread_function" function.
In the "thread_function" function, a loop iterates 100000 times,
and in each iteration, the mutex lock is acquired using
the "pthread_mutex_lock" function to ensure that
the critical section (the increment of the shared variable "counter")
is executed atomically by the thread. After incrementing the counter,
the mutex lock is released using the "pthread_mutex_unlock" function.
The two threads run concurrently and increment
the shared variable "counter" multiple times.

The final value of the counter is printed after the threads finish
their execution. Finally, the mutex lock is
destroyed using the "pthread_mutex_destroy" function.


This code creates a shared variable counter and a mutex lock lock.
It then creates two threads that both execute the thread_function function.

This function increments the shared variable counter in a critical section,
which is protected by the mutex lock.
After both threads have completed their iterations,
the final value of counter is printed to the console.

Finally, the mutex lock is destroyed.

*/

int counter = 0;      // shared variable
pthread_mutex_t lock; // mutex lock

void *thread_function(void *arg)
{
    int i;
    for (i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&lock);   // lock the critical section
        counter++;                   // increment the shared variable
        pthread_mutex_unlock(&lock); // unlock the critical section
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL); // initialize the mutex lock

    pthread_create(&thread1, NULL, thread_function, NULL); // create first thread
    pthread_create(&thread2, NULL, thread_function, NULL); // create second thread

    pthread_join(thread1, NULL); // wait for first thread to finish
    pthread_join(thread2, NULL); // wait for second thread to finish

    printf("Final value of counter: %d\n", counter); // print final value of shared variable

    pthread_mutex_destroy(&lock); // destroy the mutex lock
    return 0;
}
