#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Error, failed to create child process.");
        return 1;
    }
    else if (pid == 0)
    {
        printf("child process (pid=%d) created by P%d.\n", getpid(), getpid() % 2);
    }
    else
    {
        printf("parent process (pid=%d) created child process with pid=%d.\n", getpid(), pid);
    }

    return 0;
} // main
