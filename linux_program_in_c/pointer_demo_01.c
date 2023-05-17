#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[20];
    float gpa;
};

int main() {
    struct student *p;
    p = (struct student*) malloc(sizeof(struct student));
    p->id = 1;
    strcpy(p->name, "John");
    p->gpa = 3.8;
    printf("Student ID: %d\n", p->id);
    printf("Student Name: %s\n", p->name);
    printf("Student GPA: %.1f\n", p->gpa);
    free(p);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *second, *third;
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    free(head);
    free(second);
    free(third);
    return 0;
}
