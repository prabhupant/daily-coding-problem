#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node *head)
{
    while(head != NULL)
    {
        printf(" %d ", head->data);
        head = head->next;
    }
}

void removeDuplicatesSorted(struct Node **head_ref)   //for sorted linked lists
{
    struct Node* curr = *head_ref;
    struct Node* next_next;

    if(current == NULL)
    {
        return;
    }
    while(current->next != NULL)
    {
        if(current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}


void removeDulpicatesUnsorted(struct Node **head_ref)
{

