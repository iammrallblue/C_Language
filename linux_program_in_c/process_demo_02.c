#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid;

    //
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "fork failed.");
    }
    else if (pid == 0)
    {
        // child process
        printf("Child Process\n");
        execlp("/bin/ls", "ls", NULL); // child process executes the command "ls"
    }
    else
    {
        // parent process
        printf("Parent Process.");
        wait(NULL); // wait for child process to finish
        printf("CHild Process Finished.");
        exit(0);
    }

    return 0;
} // main
