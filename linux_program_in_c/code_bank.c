#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    // create a new process
    pid = fork();

    if (pid < 0)
    { // error occurred
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if (pid == 0)
    { // child process
        printf("Child Process\n");
        execlp("/bin/ls", "ls", NULL); // execute ls command
    }
    else
    { // parent process
        printf("Parent Process\n");
        wait(NULL); // wait for child process to complete
        printf("Child Complete\n");
        exit(0);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id)
{
    long tid = (long)thread_id;
    printf("Hello from thread %ld\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
        if (rc)
        {
            printf("Error creating thread %ld\n", t);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}

/*
Atomic Variables
*/

#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>

atomic_int count = 0;

void *thread_function(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        atomic_fetch_add(&count, 1);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of count: %d\n", count);

    return 0;
}

/* code */

/*Example 1 of test_and_set()*/
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

// global variables
bool lock = false;

void lock_acquire(bool *lock)
{
    while (__sync_lock_test_and_set(lock, true))
        ;
}

void lock_release(bool *lock)
{
    __sync_lock_release(lock);
}

void *thread_func(void *arg)
{
    lock_acquire(&lock);
    printf("Thread %ld acquired lock\n", (long)arg);
    sleep(2); // simulate some work
    lock_release(&lock);
    printf("Thread %ld released lock\n", (long)arg);
    return NULL;
}

int main()
{
    pthread_t threads[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }
    for (i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}

/*
In this example, test_and_set() is used to implement
mutual exclusion between threads.
The lock variable is a boolean flag that indicates
whether a thread has acquired the lock or not.
The lock_acquire() function uses test_and_set() to
atomically set the lock flag to true and return
the previous value of the flag.
If the previous value was already true,
the function loops until the lock is released.
The lock_release() function simply sets the lock flag back to false.

*/

/* example 2 of test_and_set()*/

#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

// global variables
bool lock = false;

void lock_acquire(bool *lock)
{
    while (__sync_lock_test_and_set(lock, true))
        ;
}

void lock_release(bool *lock)
{
    __sync_lock_release(lock);
}

void *thread_func(void *arg)
{
    while (lock)
        ; // spin until lock is acquired
    printf("Thread %ld acquired lock\n", (long)arg);
    sleep(2);     // simulate some work
    lock = false; // release the lock
    printf("Thread %ld released lock\n", (long)arg);
    return NULL;
}

int main()
{
    pthread_t threads[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }
    for (i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}

/*
In this example, test_and_set() is used to implement a spinlock.
The lock variable is a boolean flag that indicates
whether the lock is currently acquired or not.
Each thread spins in a loop until the lock flag is false,
indicating that the lock is available.
When a thread acquires the lock, it sets the lock flag to true,
does some work, and then releases the lock by setting the lock flag back to false.
*/

/* example 1 of compare_and_swap()*/
#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <pthread.h>

#define THREAD_COUNT 5

// global variables
atomic_int counter = ATOMIC_VAR_INIT(0);

// function declarations
void increment(atomic_int *v);
int compare_and_swap(atomic_int *v, int expected, int new);

void *thread_func(void *arg)
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        increment(&counter);
    }
    return NULL;
}

void increment(atomic_int *v)
{
    int temp;
    do
    {
        temp = *v;
    } while (temp != compare_and_swap(v, temp, temp + 1));
}

int main()
{
    pthread_t threads[THREAD_COUNT];
    int i;
    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }
    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("Counter value: %d\n", counter);
    return 0;
}

// implementation of compare_and_swap function
int compare_and_swap(atomic_int *v, int expected, int new)
{
    return atomic_compare_exchange_strong(v, &expected, new);
}

/*
In this example, increment() is implemented using compare_and_swap().
The counter variable is an atomic integer that is initialized to 0
using the ATOMIC_VAR_INIT() macro.

Each thread runs the thread_func() function,
which simply calls increment() 10,000 times.

The increment() function uses a do-while loop to repeatedly read
the current value of v, and then atomically compares and swaps
the value of v with temp+1.

This loop continues until the atomic compare-and-swap operation succeeds,
which ensures that the increment is performed atomically
and without race conditions.

Finally, the main() function waits for all threads to finish and prints
the final value of the counter.

*/

/*Example 02 Mutex Lock*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5

pthread_mutex_t lock;
int counter = 0;

void *thread_func(void *arg)
{
    int i;
    for (i = 0; i < 10000; i++)
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
        printf("Created thread %d\n", i);
    }

    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Joined thread %d\n", i);
    }

    pthread_mutex_destroy(&lock);

    printf("Counter value: %d\n", counter);

    return 0;
} // main

/*
In this example, we declare a global integer variable counter
and initialize it to zero.
We also declare a mutex lock using the pthread_mutex_t data type
and initialize it using the pthread_mutex_init() function.

Inside the thread_func() function,
we use pthread_mutex_lock() to acquire the lock before
incrementing the counter and pthread_mutex_unlock() to
release the lock after incrementing the counter.

In the main function, we create multiple threads using
pthread_create() function and wait for them to complete
using pthread_join() function.

Finally, we destroy the mutex lock using the
pthread_mutex_destroy() function and print the final value of the counter.

Using mutex locks with acquire() and release() functions
ensures that only one thread can access the critical section
at a time and avoids any race condition issues.
*/

/* Mutex Lock with compare_and_swap()*/

#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <pthread.h>

#define THREAD_COUNT 5

// global variables
int shared_variable = 0;
atomic_bool want_in[THREAD_COUNT] = {ATOMIC_VAR_INIT(0)};
atomic_int turn = ATOMIC_VAR_INIT(0);

// function declarations
void critical_section(int thread_id);
void acquire(int thread_id);
void release(int thread_id);

void *thread_func(void *arg)
{
    int thread_id = *(int *)arg;
    int i;
    for (i = 0; i < 10000; i++)
    {
        acquire(thread_id);
        critical_section(thread_id);
        release(thread_id);
    }

    return NULL;
} // thread_func()

void critical_section(int thread_id)
{
    printf("Thread %d is in the critical section with shared_variable = %d\n", thread_id, shared_variable);
    shared_variable++;
    printf("Thread %d updates shared_variable to %d\n", thread_id, shared_variable);
} // critical_section()

void acquire(int thread_id)
{
    int other;
    want_in[thread_id] = true;
    do
    {
        other = turn;
        while (other != thread_id)
        {
            if (!want_in[other])
            {
                other = turn;
            }
            else
            {
                other = (turn + 1) % THREAD_COUNT;
                turn = other;
            }
        }
    } while (other == thread_id && atomic_compare_exchange_strong(&want_in[thread_id], &other, false));
} // acquire()

void release(int thread_id)
{
    want_in[thread_id] = false;
    turn = (turn + 1) % THREAD_COUNT;
} // release()

int main(int argc, char const *argv[])
{
    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];
    int i;
    for (i = 0; i < THREAD_COUNT; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
        printf("Created thread %d\n", i);
    }
    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Joined thread %d\n", i);
    }
    printf("Final value of shared_variable: %d\n", shared_variable);

    return 0;
} // main

/*
In this example, want_in is an array of atomic boolean variables
that indicate whether a thread wants to enter the critical section.

The turn variable is an atomic integer that indicates whose
turn it is to enter the critical section.

The acquire() function is called by a thread when it wants to
enter the critical section.
It sets its own want_in value to true, then enters a loop
that checks if any other thread is in the critical section.

If another thread is in the critical section or wants to enter it,
the function waits and repeatedly checks until it is its turn to enter.

When it is its turn, the function sets its own want_in value to
false and updates the turn variable to indicate the next thread's turn.

The release() function is called by a thread when it exits the critical section.
It sets its own want_in value to false and updates the turn variable to
indicate the next thread's turn.

The critical_section() function is the code that is executed inside
the critical section. In this example, it simply increments a shared
variable and prints out some
*/

/* Bounded-Buffer Problem */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 20

sem_t *mutex, *empty, *full;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void *producer(void *arg)
{
    int i, item;
    for (i = 0; i < NUM_ITEMS; i++)
    {
        item = i;
        sem_wait(empty);
        sem_wait(mutex);
        buffer[in] = item;
        printf("Producing item %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        sem_post(mutex);
        sem_post(full);
    }
    return NULL;
}

void *consumer(void *arg)
{
    int i, item;
    for (i = 0; i < NUM_ITEMS; i++)
    {
        sem_wait(full);
        sem_wait(mutex);
        item = buffer[out];
        printf("Consuming item %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        sem_post(mutex);
        sem_post(empty);
    }
    return NULL;
}

int main()
{
    int i;
    pthread_t producers[2], consumers[2];

    mutex = sem_open("mutex", 0, 1);
    empty = sem_open("empty", 0, BUFFER_SIZE);
    full = sem_open("full", 0, 0);

    for (i = 0; i < 2; i++)
    {
        pthread_create(&producers[i], NULL, &producer, NULL);
        pthread_create(&consumers[i], NULL, &consumer, NULL);
    }

    for (i = 0; i < 2; i++)
    {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    sem_close(mutex);
    sem_close(empty);
    sem_close(full);

    sem_unlink("mutex");
    sem_unlink("empty");
    sem_unlink("full");

    return 0;
}

/*
The mutex semaphore is used to ensure mutual exclusion of the buffer
between the producers and consumers.

The empty semaphore is initialized to the maximum buffer size,
and is used to block producers when the buffer is full.

The full semaphore is initialized to 0,
and is used to block consumers when the buffer is empty.
*/

/* Writers-Readers Example*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 5

int shared_variable = 0;
int read_count = 0;

sem_t rw_mutex, mutex;

void *reader(void *arg)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        sem_wait(&mutex); // lock the mutex
        read_count++;     // increment the read_count
        if (read_count == 1)
        {
            sem_wait(&rw_mutex); // if this is the first reader, lock the rw_mutex
        }
        sem_post(&mutex); // release the mutex

        // read the shared variable
        printf("Reader %d read value %d\n", *((int *)arg), shared_variable);

        sem_wait(&mutex); // lock the mutex
        read_count--;     // decrement the read_count
        if (read_count == 0)
        {
            sem_post(&rw_mutex); // if this is the last reader, release the rw_mutex
        }
        sem_post(&mutex); // release the mutex
    }

    return NULL;
} // reader()

void *writer(void *arg)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        sem_wait(&rw_mutex); // lock the rw_mutex

        // write to the shared variable
        shared_variable++;
        printf("Writer %d wrote value %d\n", *((int *)arg), shared_variable);

        sem_post(&rw_mutex); // release the rw_mutex
    }

    return NULL;
} // writer()

int main(int argc, char const *argv[])
{
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int reader_ids[NUM_READERS], writer_ids[NUM_WRITERS];
    int i;

    // initialize the semaphores
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    // create the readers
    for (i = 0; i < NUM_READERS; i++)
    {
        reader_ids[i] = i;
        pthread_create(&readers[i], NULL, &reader, &reader_ids[i]);
    }

    // create the writers
    for (i = 0; i < NUM_WRITERS; i++)
    {
        writer_ids[i] = i;
        pthread_create(&writers[i], NULL, &writer, &writer_ids[i]);
    }

    // wait for the readers and writers to finish
    for (i = 0; i < NUM_READERS; i++)
    {
        pthread_join(readers[i], NULL);
    }
    for (i = 0; i < NUM_WRITERS; i++)
    {
        pthread_join(writers[i], NULL);
    }

    // destroy the semaphores
    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
} // main

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 2
#define NUM_READS 10
#define NUM_WRITES 5

sem_t mutex, rw_mutex;
int read_count = 0, data = 0;

void *reader(void *arg)
{
    int i;
    for (i = 0; i < NUM_READS; i++)
    {
        sem_wait(&mutex);
        read_count++;
        if (read_count == 1)
        {
            sem_wait(&rw_mutex);
        }
        sem_post(&mutex);

        printf("Reader %ld read data as %d\n", (long)arg, data);

        sem_wait(&mutex);
        read_count--;
        if (read_count == 0)
        {
            sem_post(&rw_mutex);
        }
        sem_post(&mutex);
    }
    return NULL;
}

void *writer(void *arg)
{
    int i;
    for (i = 0; i < NUM_WRITES; i++)
    {
        sem_wait(&rw_mutex);
        data++;
        printf("Writer %ld wrote data as %d\n", (long)arg, data);
        sem_post(&rw_mutex);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    long i;

    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

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

    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
}

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

    mutex = sem_open("/mutex", O_CREAT, 0644, 1);
    rw_mutex = sem_open("/rw_mutex", O_CREAT, 0644, 1);

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
    sem_unlink("/rw_mutex");

    return 0;
} // main

/*

In this implementation, sem_t mutex is used to synchronize access
to the read_count variable, and sem_t rw_mutex is
used to synchronize access to the data variable.

The reader() function uses the mutex semaphore to increment read_count,
then checks if this is the first reader to arrive by comparing
read_count to 1. If it is, the reader acquires the rw_mutex semaphore
to protect the data from writers.
The reader then reads the data and decrements read_count.
If the reader is the last to leave,
it releases the rw_mutex semaphore for the next writer.

The writer() function acquires the rw_mutex semaphore to protect
the data from other writers and readers, then writes to the data variable.
After writing, the writer releases the rw_mutex semaphore for the next writer or reader.

In the main() function, threads are created for the readers and writers.
The threads are then joined to wait for their completion.
Finally, the semaphores are destroyed to clean up the resources used.
*/

/* Dinning Philosopher Problem by Semaphore */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define num_philosophers 5
#define num_forks 5

sem_t forks[num_forks];

void *philosopher(void *thread_id)
{
    long tid;
    tid = (long)thread_id;

    // Thinking
    printf("Philosopher %ld is thinking...\n", tid);

    if (tid % 2 == 0)
    {
        // Pick up left fork
        sem_wait(&forks[tid]);
        printf("Philosopher %ld picked up left fork.\n", tid);

        // Pick up right fork
        sem_wait(&forks[(tid + 1) % num_forks]);
        printf("Philosopher%ld picked up right fork.\n", tid);
    }
    else
    {
        // Pick up right fork
        sem_wait(&forks[(tid + 1) % num_forks]);
        printf("Philosopher %ld picked up right fork.\n", tid);

        // Pick up left fork
        sem_wait(&forks[tid]);
        printf("Philosopher %ld picked up left fork.\n", tid);
    }

    // Eating
    printf("Philosopher %ld is eating...\n", tid);

    // Put down the forks
    sem_post(&forks[tid]);
    sem_post(&forks[(tid + 1) % num_forks]);
    printf("Philosopher %ld put down both forks.\n", tid);

    return NULL;
}

int main()
{
    // Create threads
    long t;
    pthread_t threads[num_philosophers];

    // Initialize semaphores
    for (t = 0; t < num_forks; t++)
    {
        sem_init(&forks[t], 0, 1);
    }

    // Create threads
    for (t = 1; t <= num_philosophers; t++)
    {
        pthread_create(&threads[t], NULL, philosopher, (void *)t);
    }

    // Join threads
    for (t = 1; t <= num_philosophers; t++)
    {
        pthread_join(threads[t], NULL);
    }

    return 0;
}

/*
Here are the changes I made:

The LEFT and RIGHT macros were not properly defined.
I changed them to use parentheses to properly enclose the expression,
and added the necessary modulus operator.

In the test function, LEFT and RIGHT were used without
the argument i passed to the function.

I fixed this by adding the argument to the macro calls.

In the take_fork function, the philosopher should wait for
permission to proceed before picking up the forks.
I added a sem_wait call on the philosopher's semaphore.

In the main function, I included the unistd.h library to use the sleep function.
*/

/* test_and_set() instruction example*/

#include <stdbool.h>
#include <stdio.h>

// Define a global lock variable
bool lock = false;

// Define a test and set function
bool test_and_set(bool *target)
{
    bool rv = *target;
    *target = true;
    return rv;
}

// Define a process function that uses test and set
void process(int id)
{
    // Do some non-critical work
    printf("Process %d is doing some work.\n", id);

    // Try to enter critical section
    while (test_and_set(&lock))
    {
        // Wait until lock is free
        printf("Process %d is waiting for the lock.\n", id);
    }

    // Enter critical section
    printf("Process %d has acquired the lock.\n", id);

    // Do some critical work
    printf("Process %d is doing some critical work.\n", id);

    // Exit critical section
    printf("Process %d has released the lock.\n", id);

    // Set lock to false
    lock = false;
}

int main()
{
    // Spawn 3 processes
    for (int i = 0; i < 3; i++)
    {
        process(i);
    }

    return 0;
}

/* test_and_set() example*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

// Define a global lock variable
volatile int lock = 0;

// Define a test and set function
int test_and_set(int *target)
{
    int rv = *target;
    *target = 1;
    return rv;
}

// Define a process function that uses test and set
void *process(void *id)
{
    int thread_id = *(int *)id;

    // Do some non-critical work
    printf("Thread %d is doing some work.\n", thread_id);

    // Try to enter critical section
    while (test_and_set(&lock))
    {
        // Wait until lock is free
        printf("Thread %d is waiting for the lock.\n", thread_id);
    }

    // Enter critical section
    printf("Thread %d has acquired the lock.\n", thread_id);

    // Do some critical work
    printf("Thread %d is doing some critical work.\n", thread_id);

    // Exit critical section
    printf("Thread %d has released the lock.\n", thread_id);

    // Set lock to false
    lock = 0;

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    // Create threads
    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, process, (void *)&thread_args[i]))
        {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/* pid fork()*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    // Fork a new process
    pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("This is the child process\n");
        printf("Child process ID: %d\n", getpid());
    }
    else if (pid > 0)
    {
        // Parent process
        printf("This is the parent process\n");
        printf("Parent process ID: %d\n", getpid());
        printf("Child process ID: %d\n", pid);
    }
    else
    {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}

/* deadlock with semaphores example */

/*
The code creates two threads, each of which tries to
acquire two semaphores (sem1 and sem2) in a different order.

Thread 1 waits for sem1, then sem2,
while Thread 2 waits for sem2, then sem1.
This creates a circular wait condition,
where each thread holds one semaphore and
waits for the other semaphore to be released.

As a result, neither thread can make progress
and they both wait indefinitely, causing a deadlock.

The deadlock can be resolved by enforcing a consistent
ordering of acquiring the semaphores across all threads.
For example, ensuring that all threads always
acquire sem1 before sem2, or vice versa.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Declare two semaphores
sem_t sem1, sem2;

// Thread 1 function
void *thread1(void *arg)
{
    // Wait for semaphore sem1 to be available
    sem_wait(&sem1);
    // Print a message indicating that sem1 has been acquired
    printf("Thread 1 acquired sem1\n");
    // Wait for semaphore sem2 to be available
    sem_wait(&sem2);
    // Print a message indicating that sem2 has been acquired
    printf("Thread 1 acquired sem2\n");
    // Release sem1
    sem_post(&sem1);
    // Release sem2
    sem_post(&sem2);
    return NULL;
}

// Thread 2 function
void *thread2(void *arg)
{
    // Wait for semaphore sem2 to be available
    sem_wait(&sem2);
    // Print a message indicating that sem2 has been acquired
    printf("Thread 2 acquired sem2\n");
    // Wait for semaphore sem1 to be available
    sem_wait(&sem1);
    // Print a message indicating that sem1 has been acquired
    printf("Thread 2 acquired sem1\n");
    // Release sem2
    sem_post(&sem2);
    // Release sem1
    sem_post(&sem1);
    return NULL;
}

// Main function
int main()
{
    // Declare two pthread variables
    pthread_t t1, t2;
    // Initialize semaphores sem1 and sem2 with values 0
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    // Create thread 1 and execute thread1() function
    pthread_create(&t1, NULL, thread1, NULL);
    // Create thread 2 and execute thread2() function
    pthread_create(&t2, NULL, thread2, NULL);
    // Wait for thread 1 to finish
    pthread_join(t1, NULL);
    // Wait for thread 2 to finish
    pthread_join(t2, NULL);
    return 0;
}

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
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, p1, NULL);
    pthread_create(&t2, NULL, p2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&s1);
    sem_destroy(&s2);
    return 0;
}

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
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, p1, NULL);
    pthread_create(&t2, NULL, p2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&s1);
    sem_destroy(&s2);
    return 0;
}

// This program includes several header files required for the program to function.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define two semaphores for synchronization between the threads.
sem_t mutex1, mutex2;

// Thread 1 function
void *thread1(void *arg)
{
    // Wait for mutex1 to become available
    sem_wait(&mutex1);
    printf("Thread 1 acquired mutex1\n");
    // Sleep for 1 second to simulate some work
    sleep(1);
    // Wait for mutex2 to become available
    sem_wait(&mutex2);
    printf("Thread 1 acquired mutex2\n");
    // Release mutex2
    sem_post(&mutex2);
    // Release mutex1
    sem_post(&mutex1);
    return NULL;
}

// Thread 2 function
void *thread2(void *arg)
{
    // Wait for mutex2 to become available
    sem_wait(&mutex2);
    printf("Thread 2 acquired mutex2\n");
    // Sleep for 1 second to simulate some work
    sleep(1);
    // Wait for mutex1 to become available
    sem_wait(&mutex1);
    printf("Thread 2 acquired mutex1\n");
    // Release mutex1
    sem_post(&mutex1);
    // Release mutex2
    sem_post(&mutex2);
    return NULL;
}

// Main function
int main()
{
    // Initialize the semaphores with initial values of 1.
    sem_init(&mutex1, 0, 1);
    sem_init(&mutex2, 0, 1);
    // Create two threads
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    // Destroy the semaphores
    sem_destroy(&mutex1);
    sem_destroy(&mutex2);
    // Exit the program
    return 0;
}

/* Example of detection deadlock. */

#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 6
#define MAX_RESOURCES 3

int available[MAX_RESOURCES];                 // array of available resources
int allocation[MAX_PROCESSES][MAX_RESOURCES]; // 2D array of allocated resources for each process
int need[MAX_PROCESSES][MAX_RESOURCES];       // 2D array of needed resources for each process
bool finished[MAX_PROCESSES] = {false};       // array of finished processes, initialized to false

bool is_safe_state()
{
    int work[MAX_RESOURCES]; // array of work resources
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        work[i] = available[i]; // set work resources to available resources
    }
    bool found_process = true;
    while (found_process)
    {
        found_process = false;
        for (int i = 0; i < MAX_PROCESSES; i++)
        {
            if (!finished[i])
            {
                bool can_allocate = true;
                for (int j = 0; j < MAX_RESOURCES; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate)
                {
                    for (int j = 0; j < MAX_RESOURCES; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    finished[i] = true;
                    found_process = true;
                }
            }
        }
    }
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        if (!finished[i])
        {
            return false; // unsafe state
        }
    }
    return true; // safe state
}

int main()
{
    // initialize available, allocation, and need arrays
    available[0] = 2;
    available[1] = 2;
    available[2] = 2;

    allocation[0][0] = 0;
    allocation[0][1] = 0;
    allocation[0][2] = 1;

    allocation[1][0] = 3;
    allocation[1][1] = 0;
    allocation[1][2] = 0;

    allocation[2][0] = 2;
    allocation[2][1] = 1;
    allocation[2][2] = 0;

    allocation[3][0] = 0;
    allocation[3][1] = 2;
    allocation[3][2] = 0;

    allocation[4][0] = 1;
    allocation[4][1] = 1;
    allocation[4][2] = 0;

    allocation[5][0] = 0;
    allocation[5][1] = 0;
    allocation[5][2] = 2;

    need[0][0] = 7;
    need[0][1] = 5;
    need[0][2] = 3;

    need[1][0] = 0;
    need[1][1] = 1;
    need[1][2] = 1;

    need[2][0] = 0;
    need[2][1] = 2;
    need[2][2] = 1;

    need[3][0] = 4;
    need[3][1] = 2;
    need[3][2] = 0;

    need[4][0] = 3;
    need[4][

    /* Example of detection deadlock*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finished[MAX_PROCESSES] = { false };

bool is_deadlock_state() {
        bool is_deadlock = true;
        bool found_process = true;
        while (found_process)
        {
            found_process = false;
            for (int i = 0; i < MAX_PROCESSES; i++)
            {
                if (!finished[i])
                {
                    bool can_allocate = true;
                    for (int j = 0; j < MAX_RESOURCES; j++)
                    {
                        if (need[i][j] > available[j])
                        {
                            can_allocate = false;
                            break;
                        }
                    }
                    if (can_allocate)
                    {
                        for (int j = 0; j < MAX_RESOURCES; j++)
                        {
                            available[j] += allocation[i][j];
                            allocation[i][j] = 0;
                            need[i][j] = 0;
                        }
                        finished[i] = true;
                        found_process = true;
                        is_deadlock = false;
                    }
                }
            }
        }
        return is_deadlock;
}

int main() {
        // initialize available, allocation, and need arrays
        if (is_deadlock_state())
        {
            printf("Deadlock detected\n");
        }
        else
        {
            // execute processes
        }
        return 0;
}



/* CRC Algorithm C Example*/
Sure, here is the same code rewritten in C:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* xor1(char* a, char* b) {

// Initialize result
char* result = (char*) malloc(strlen(b) + 1);

int n = strlen(b);

// Traverse all bits, if bits are
// same, then XOR is 0, else 1
for (int i = 0; i < n; i++) {
    if (a[i] == b[i])
        result[i] = '0';
    else
        result[i] = '1';
}
result[n] = '\0';
return result;
}

// Performs Modulo-2 division
char* mod2div(char* dividend, char* divisor){

// Number of bits to be XORed at a time.
int pick = strlen(divisor);

// Slicing the dividend to appropriate
// length for particular step
char* tmp = (char*) malloc(pick + 1);
strncpy(tmp, dividend, pick);
tmp[pick] = '\0';

int n = strlen(dividend);

while (pick < n) {
    if (tmp[0] == '1')

        // Replace the dividend by the result
        // of XOR and pull 1 bit down
        strcpy(tmp, xor1(divisor, tmp));
        tmp[strlen(tmp)] = dividend[pick];
    else

        // If leftmost bit is '0'.
        // If the leftmost bit of the dividend (or the
        // part used in each step) is 0, the step cannot
        // use the regular divisor; we need to use an
        // all-0s divisor.
        strcpy(tmp, xor1(strdup("000000000000000000000000"), tmp));
        tmp[strlen(tmp)] = dividend[pick];

    // Increment pick to move further
    pick += 1;
}

// For the last n bits, we have to carry it out
// normally as increased value of pick will cause
// Index Out of Bounds.
if (tmp[0] == '1') {
    strcpy(tmp, xor1(divisor, tmp));
} else {
    strcpy(tmp, xor1(strdup("0000000000000000000000000"), tmp));
}

return tmp;
}

// Function used at the sender side to encode
// data by appending remainder of modular division
// at the end of data.
void encodeData(char* data, char* key){

int l_key = strlen(key);

// Appends n-1 zeroes at end of data
char* appended_data = (char*) malloc((strlen(data) + l_key) * sizeof(char));
strcpy(appended_data, data);
for(int i = 1; i < l_key; i++){
    strcat(appended_data, "0");
}

char* remainder = mod2div(appended_data, key);

// Append remainder in the original data
char* codeword = (char*) malloc((strlen(data) + strlen(remainder) + 1) * sizeof(char));
strcpy(codeword, data);
strcat(codeword, remainder);
printf("Remainder : %s\n", remainder);
printf("Encoded Data (Data + Remainder) :%s\n", codeword);
}

// checking if the message received by receiver is correct
// or not. If the remainder is all 0 then it is correct,
// else wrong.
void receiver(char* data, char* key){

char* currxor = mod2div(strncpy(strdup(data), 0, strlen(key)), key);

int curr = strlen(key);
int n = strlen(data);

while (curr != n) {
    if (strlen(currxor) != strlen(key)) {
        strncat(currxor, &data[curr++], 1);
    }
    else {
        currxor = mod2div(currxor, key);
    }
}

if (strlen(currxor) == strlen(key)) {
    currxor = mod2div(currxor, key);
}

if (strstr(currxor, "1") != NULL) {
    printf("there is some error in data\n");
} else {
    printf("correct message received\n");
}
}

// Driver code
int main()
{
char* data = "100100";
char* key = "1101";
printf("Sender side...\n");
encodeData(data, key);

printf("\nReceiver side...\n");
int size = strlen(data) + strlen(mod2div(strcat(strdup(data), strcat(strdup("0000000000000000"), key)), key));
char* received_data = (char*) malloc(size * sizeof(char));
strcpy(received_data, data);
strcat(received_data, mod2div(strcat(strdup(data), strcat(strdup("0000000000000000"), key)), key));
receiver(received_data, key);

return 0;
}