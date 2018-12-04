#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void pairwiseSwap(struct Node **head_ref)
{
    if(*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    struct Node *prev = *head_ref;
    struct Node *curr = (*head_ref)->next;

    *head_ref = curr;

    while(true)
    {
        struct Node *next = curr->next;
        curr->next = prev;

        if(next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
}

void push(struct Node **head_ref, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main()
{
    struct Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    printf("Before swapping : \n");
    printList(head);
    printf("\nAfter swapping : \n");
    pairwiseSwap(&head);
    printList(head);
    return 0;
}

