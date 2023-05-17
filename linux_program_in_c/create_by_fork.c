#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int pid1 = fork();
    int pid2 = fork();
    int pid3 = fork();

    // pid1
    if (pid1 == 0)
    {
        printf("child process 1: pid= %d, ppid=%d\n", getpid(), getppid());
    }
    else if (pid1 > 0)
    {
        printf("parent process: pid=%d\n", getpid());
    }
    else
    {
        printf("Error, fork process failed\n");
    }

    // pid2
    if (pid2 == 0)
    {
        printf("child process 2: pid=%d, ppid=%d\n", getpid(), getppid());
    }
    else if (pid2 > 0)
    {
        printf("parent process: pid=%d\n", getpid());
    }
    else
    {
        printf("Error, fork process failed.\n");
    }

    // pid3
    if (pid3 == 0)
    {
        printf("child process 3: pid=%d, ppid=%d\n", getpid(), getppid());
    }
    else if (pid3 > 0)
    {
        printf("parent process: pid=%d\n", getpid());
    }
    else
    {
        printf("error, fork process failed.\n");
    }

    return 0;

} // main
