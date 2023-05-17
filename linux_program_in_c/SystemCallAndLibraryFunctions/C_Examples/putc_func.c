#include <stdio.h>
#include <stdlib.h>

/*
    putc function:
        int putc(int char, FILE *stream)
            writes a character (an unsigned char) specified by
            the argument char to the specified stream and
            advances the position indicator for the stream.

            Parameters
                char − This is the character to be written.
                The character is passed as its int promotion.

                stream − This is the pointer to a FILE object
                        that identifies the stream where
                        the character is to be written.

            Return Value
                This function returns the character written
                 as an unsigned char cast to an int or EOF on error.
*/
int main(int argc, char *argv[])
{
    FILE *fptr; // FILE pointer

    fptr = fopen("emp", "w"); // open the file emp in write-mode

    // dealing the content which will write into the file emp
    for (int i = 33; i < 100; i++)
    {
        putc(i, fptr); // write character from 33 to 99
    }                  // for

    fclose(fptr);

    // reading the content of the file "emp"

    fptr = fopen("emp", "r");
    while (1)
    {
        int ch = fgetc(fptr);
        if (feof(fptr))
        {
            break;
        } // if
        printf("%c", ch);

    } // while

    fclose(fptr);

    return 0;
} // main

/* example of how to use a mutex in C on Linux for synchronization. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

int counter = 0;
pthread_mutex_t lock;

void *increment(void *thread_id)
{
    long tid = (long)thread_id;
    printf("Thread %ld is starting...\n", tid);
    pthread_mutex_lock(&lock); // Acquire the mutex lock
    printf("Thread %ld has acquired the lock...\n", tid);
    counter++; // Increment the shared counter
    printf("Thread %ld incremented the counter to %d...\n", tid, counter);
    pthread_mutex_unlock(&lock); // Release the mutex lock
    printf("Thread %ld has released the lock...\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    // Initialize the mutex lock
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex initialization failed.\n");
        exit(1);
    }
    // Create the threads
    for (t = 0; t < NUM_THREADS; t++)
    {
        rc = pthread_create(&threads[t], NULL, increment, (void *)t);
        if (rc)
        {
            printf("Error: Unable to create thread %ld\n", t);
            exit(1);
        }
    }
    // Wait for the threads to finish
    for (t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
    }
    // Destroy the mutex lock
    pthread_mutex_destroy(&lock);
    printf("Final counter value: %d\n", counter);
    pthread_exit(NULL);
}

/*
In this example, we have a shared counter variable that we want to
increment using multiple threads.

We define a mutex lock lock to protect the counter variable from concurrent access.

In the increment function, each thread acquires the
lock using pthread_mutex_lock, increments the shared counter,
and releases the lock using pthread_mutex_unlock.

In the main function, we create 10 threads to increment the counter, and we wait for them to finish using pthread_join. Finally, we destroy the mutex lock using pthread_mutex_destroy and print the final value of the counter.

By using a mutex lock, we ensure that only one thread can access the shared counter variable at a time, preventing any race conditions that could lead to incorrect results.

*/

/* example for ...*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // KEY
int count = 1;                                    // SHARED VARIABLE AMONG THREADS
int numOfPrimes = 0;
void countNumberOfPrimeNumber(void *empty)
{
    do
    {
        int num = 2;
        pthread_mutex_lock(&lock); // blocked
        int localCount = ++count;  // VERY IMPORTANT
        pthread_mutex_unlock(&lock);
        for (num = 2; num < localCount; num++)
        {
            if (localCount % num == 0)
                break;
        }
        if (num == localCount)
        {
            pthread_mutex_lock(&lock); // blocked
            numOfPrimes++;
            pthread_mutex_unlock(&lock);
            // printf ( "prime number : %d %d \n", numOfPrimes, count);
        }
    } while (count < 200000);
}

void main()
{
    int pid;
    pid = vfork();
    if (pid < 0)
    {
        printf("\n Error ");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Hello from Child!\n");
        pthread_t T1, T2;
        int id1, id2;
        clock_t start, end;
        struct tms st_start, st_end;
        start = times(&st_start);
        pthread_t t1, t2, t3; // two threads
        int thread1;
        int thread2;
        int thread3;
        thread1 = pthread_create(&t1, NULL, (void *)countNumberOfPrimeNumber, (void *)NULL);
        thread2 = pthread_create(&t2, NULL, (void *)countNumberOfPrimeNumber, (void *)NULL);
        thread3 = pthread_create(&t3, NULL, (void *)countNumberOfPrimeNumber, (void *)NULL);
        if (thread1 == 0)
            printf(" Thread 1 success \n");
        if (thread2 == 0)
            printf(" Thread 2 success \n");
        if (thread3 == 0)
            printf(" Thread 3 success \n");
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        pthread_join(t3, NULL);
        end = times(&st_end);
        printf("Time taken by system command %6.2f \n", (float)(end - start) / sysconf(_SC_CLK_TCK));
        printf("Time taken by parent process in User mode %6.2f \n", (float)(st_end.tms_utime) / sysconf(_SC_CLK_TCK));
        printf("Time taken by parent process in Kernel mode %6.2f \n", (float)(st_end.tms_stime) / sysconf(_SC_CLK_TCK));
        printf("Time taken by child process in user mode %6.2f \n", (float)(st_end.tms_cutime) / sysconf(_SC_CLK_TCK));
        printf("Time taken by child process in kernel mode %6.2f \n", (float)(st_end.tms_cstime) / sysconf(_SC_CLK_TCK));
        printf("Number of prime numbers : %d \n", numOfPrimes);
    }

    // parent process because return value non-zero.
    else
        printf("Hello from Parent!\n");
}

/* Making a process in user-level by using fork() system call

Making a thread in user-level by using pthread APIs

Making a kernel thread in your kernel module */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t forkStatus;

    forkStatus = fork();

    /* Child... */
    if (forkStatus == 0)
    {
        printf("Child is running, processing.\n");
        sleep(5);
        printf("Child is done, exiting.\n");

        /* Parent... */
    }
    else if (forkStatus != -1)
    {
        printf("Parent is waiting...\n");

        wait(NULL);
        printf("Parent is exiting...\n");
    }
    else
    {
        perror("Error while calling the fork function");
    }

    return 0;
}

Making a thread in user - level by using pthread APIs

// C program to show thread functions
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PAGE_SIZE 256
#define NUM_PAGES 256
#define NUM_FRAMES 256
#define SWAP_SPACE_SIZE 65536

int page_table[NUM_PAGES];
int frame_table[NUM_FRAMES];
char main_memory[NUM_FRAMES][PAGE_SIZE];
char swap_space[SWAP_SPACE_SIZE];

int swap_space_fd; // declare swap_space_fd as a global variable

// handle_page_fault
void handle_page_fault(int page_number)
{
    // check if the page table entry is valid
    if (page_table[page_number] == -1)
    {
        // page fault occurred
        printf("page fault: page %d\n", page_number);

        // read the page from swap space
        int swap_offset = page_number * PAGE_SIZE;
        int frame_number = -1;
        for (int i = 0; i < NUM_FRAMES; i++)
        {
            if (frame_table[i] == -1)
            {
                frame_number = i;
                break;
            }
        }
        if (frame_number == -1)
        {
            printf("error: no free frames available\n");
            exit(1);
        }

        int main_memory_offset = frame_number * PAGE_SIZE;
        lseek(swap_space_fd, swap_offset, SEEK_SET);
        read(swap_space_fd, main_memory[main_memory_offset], PAGE_SIZE);

        // update the page table and frame table
        page_table[page_number] = frame_number;
        frame_table[frame_number] = page_number;
    }
} // handle_page_fault()

int main(int argc, char const *argv[])
{
    // initialize page table and frame table
    for (int i = 0; i < NUM_PAGES; i++)
    {
        page_table[i] = -1;
    }
    for (int i = 0; i < NUM_FRAMES; i++)
    {
        frame_table[i] = -1;
    }

    // open the swap space file
    swap_space_fd = open("swap_space_bin", O_RDWR | O_CREAT, 0644);
    if (swap_space_fd == -1)
    {
        perror("error opening swap space file");
        exit(1);
    }

    // simulate a program accessing pages
    int page_number = 0;
    while (1)
    {
        handle_page_fault(page_number);

        // access the next page
        page_number = (page_number + 1) % NUM_PAGES;
        usleep(1000);
    }

    return 0;
} // main()



/* .... */

#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 256
#define NUM_PAGES 256
#define NUM_FRAMES 256

int page_table[NUM_PAGES];
int frame_table[NUM_FRAMES];
char main_memory[NUM_FRAMES][PAGE_SIZE];

void handle_page_fault(int page_number) {
    // Check if the page table entry is valid
    if (page_table[page_number] == -1) {
        // Page fault occurred
        printf("Page fault: page %d\n", page_number);

        // Find a free frame
        int frame_number = -1;
        for (int i = 0; i < NUM_FRAMES; i++) {
            if (frame_table[i] == -1) {
                frame_number = i;
                break;
            }
        }
        if (frame_number == -1) {
            printf("Error: no free frames available\n");
            exit(1);
        }

        // Copy the page into the main memory frame
        int main_memory_offset = frame_number * PAGE_SIZE;
        int page_offset = page_number *
