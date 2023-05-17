#include <stdio.h>
#include <stdbool.h>

#define SIZE 5 // constant to limit the size of stack

int top = 0;
int stack[SIZE]; // define an int array named stack for storing numbers.

bool is_empty(); // declare the is_empty() function

/*
    push() function, to push number to stack
*/
void push(int num)
{
    // check top is not larger than SIZE
    if (top < SIZE)
    {
        stack[top] = num;
        top++;
    }
    else
    {
        printf("Error, stack is full.");
    }

} // push

/*
    pop() funciton,

*/
int pop()
{
    if (!is_empty())
    {
        top--;
        return stack[top];
    }
    else
    {
        printf("Error, stack is empty!");
        return -1;
    }

} // pop

/*
    is_empty() funciton, check top-- decreases to 0
*/
bool is_empty()
{
    if (top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

} // is_empty

int main(int argc, char const *argv[])
{
    push(22);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
} // main
