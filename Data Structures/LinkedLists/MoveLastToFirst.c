#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void push(struct Node **head_ref, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void lastToFirst(struct Node **head_ref)
{
    if(*head_ref == NULL || (*head_ref)->next == NULL)
    {
        printf("The operation is not possible on this list!");
        return;
    }

    struct Node* last = *head_ref;
    struct Node* second_last = NULL;

    while(last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
}

int main()
{
    struct Node *head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("The elements of the list are : \n");
    printList(head);
    printf("\nAfter lastToFirst(), elements of the list are : \n");
    lastToFirst(&head);
    printList(head);
    return 0;
}



    
