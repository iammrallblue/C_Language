#include <stdio.h>
#include <unistd.h>

/*
"pid == 0" is a condition that checks if the current process
is the child process created by a parent process using the fork() system call.

If "pid == 0" is true, it means the current process is the child process.

"pid > 0" is a condition that checks if the value of pid is greater than zero.

If "pid > 0" is true, it means the current process is the parent process,
and the value of pid is the process ID of the child process it created using fork().
*/

int main(int argc, char const *argv[])
{
    pid_t pid;

    // fork a new process
    pid = fork();

    if (pid == 0)
    { // 0, child process is created

        printf("new child process\n");
        printf("child process id: %d\n", getpid());
    }
    else if (pid > 0)
    {
        printf("The parent process\n");
        printf("parent process id: %d\n", getpid());
    }
    else
    {
        fprintf(stderr, "fork failed\n");

        return 1;
    }

    return 0;
}
