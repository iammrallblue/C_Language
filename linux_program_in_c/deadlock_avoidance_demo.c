#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Maximum number of processes
#define MAX_PROCESSES 10

// Maximum number of resource types
#define MAX_RESOURCES 10

// Available resources
int available[MAX_RESOURCES];

// Maximum demand of each process
int maximum[MAX_PROCESSES][MAX_RESOURCES];

// Resources allocated to each process
int allocation[MAX_PROCESSES][MAX_RESOURCES];

// Remaining need of each process
int need[MAX_PROCESSES][MAX_RESOURCES];

// Number of processes and resources
int num_processes, num_resources;

// Function to check if request is safe
bool is_safe(int process_id, int request[])
{
    // Temporary arrays to hold the state of the system
    int temp_available[MAX_RESOURCES];
    int temp_allocation[MAX_PROCESSES][MAX_RESOURCES];
    int temp_need[MAX_PROCESSES][MAX_RESOURCES];

    // Copy the current state to the temporary state
    for (int i = 0; i < num_resources; i++)
    {
        temp_available[i] = available[i];
        for (int j = 0; j < num_processes; j++)
        {
            temp_allocation[j][i] = allocation[j][i];
            temp_need[j][i] = need[j][i];
        }
    }

    // Grant the request
    for (int i = 0; i < num_resources; i++)
    {
        temp_available[i] -= request[i];
        temp_allocation[process_id][i] += request[i];
        temp_need[process_id][i] -= request[i];
    }

    // Initialize the work array and the finish array
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES];
    for (int i = 0; i < num_resources; i++)
    {
        work[i] = temp_available[i];
    }
    for (int i = 0; i < num_processes; i++)
    {
        finish[i] = false;
    }

    // Find a process that can be finished
    bool found = true;
    while (found)
    {
        found = false;
        for (int i = 0; i < num_processes; i++)
        {
            if (!finish[i])
            {
                bool can_finish = true;
                for (int j = 0; j < num_resources; j++)
                {
                    if (temp_need[i][j] > work[j])
                    {
                        can_finish = false;
                        break;
                    }
                }
                if (can_finish)
                {
                    for (int j = 0; j < num_resources; j++)
                    {
                        work[j] += temp_allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
    }

    // Check if all processes are finished
    for (int i = 0; i < num_processes; i++)
    {
        if (!finish[i])
        {
            return false;
        }
    }

    return true;
} // is_safe()

// Function to request resources
bool request_resources(int process_id, int request[])
{
    // Check if the request is valid
    for (int i = 0; i < num_resources; i++)
    {
        if (request[i] > need[process_id][i])
        {
            printf("Error: process %d exceeded its maximum claim\n", process_id);
            return false;
        }
        if (request[i] > available[i])
        {
            printf("Process %d is blocked\n", process_id);
            return false;
        }
    }

    // Try to grant the request
    if (is_safe(process_id, request))
    {
        for (int i = 0; i < num_resources; i++)
        {
            // Grant resource i
            available[i] -= request[i];
            allocation[process_id][i] += request[i];
            need[process_id][i] -= request[i];
        }
        return true; // Request was granted
    }
    else
    {
        return false; // Request was not granted
    }
} // request_resources()

int main()
{
    // Initialize the available resources

    num_resources = 3;
    available[0] = 3;

    available[1] = 3;
    available[2] = 2;

    // Initialize the maximum demand of each process
    num_processes = 5;
    maximum[0][0] = 7;
    maximum[0][1] = 5;
    maximum[0][2] = 3;
    maximum[1][0] = 3;
    maximum[1][1] = 2;
    maximum[1][2] = 2;
    maximum[2][0] = 9;
    maximum[2][1] = 0;
    maximum[2][2] = 2;
    maximum[3][0] = 2;
    maximum[3][1] = 2;
    maximum[3][2] = 2;
    maximum[4][0] = 4;
    maximum[4][1] = 3;
    maximum[4][2] = 3;

    // Initialize the allocation and need arrays
    for (int i = 0; i < num_processes; i++)
    {
        for (int j = 0; j < num_resources; j++)
        {
            allocation[i][j] = 0;
            need[i][j] = maximum[i][j];
        }
    }

    // Test the request_resources function
    int process_id = 0;
    int request[] = {2, 2, 1};
    bool granted = request_resources(process_id, request);
    if (granted)
    {
        printf("Process %d was granted its request\n", process_id);
    }
    else
    {
        printf("Process %d was not granted its request\n", process_id);
    }

    return 0;
} // main()
