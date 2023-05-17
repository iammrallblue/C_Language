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

int swap_space_fd;

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
    int swap_space_fd = open("swap_space_bin", O_RDWR | O_CREAT, 0644);
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
