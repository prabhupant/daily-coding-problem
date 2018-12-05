#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printMiddle(struct Node *head)
{
    struct Node *curr = head;
    struct Node *middle = head;
    int size = 0;
    while(curr != NULL)
    {
        size++;
        if(size % 2 == 0)
        {
            middle = middle->next;
        }
        curr = curr->next;
    }
    printf("\nThe middle of the list is : %d", middle->data);
}

void printList(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct Node *head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("The list is : \n");
    printList(head);
    printMiddle(head);
    return 0;
}

