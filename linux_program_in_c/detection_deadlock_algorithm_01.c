#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 6
#define MAX_RESOURCES 3

int available[MAX_PROCESSES];                 // array of available resources
int allocation[MAX_PROCESSES][MAX_RESOURCES]; // 2d array of allocated resource for each process
int need[MAX_PROCESSES][MAX_RESOURCES];       // 2d array of needed resources for each process
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

    } // while
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        if (!finished[i])
        {
            return false; // unsafe state
        }
    }
    return true; // safe state

} // is_safe_state()

int main(int argc, char const *argv[])
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
    need[4][1] = 3;
    need[4][2] = 2;

    need[5][0] = 0;
    need[5][1] = 0;
    need[5][2] = 2;

    bool safe = is_safe_state();
    if (safe)
    {
        printf("The current state is safe.\n");
    }
    else
    {
        printf("The current state is not safe.\n");
    }

    return 0;
}
