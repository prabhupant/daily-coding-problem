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

void segregateEvenOdd(struct Node **head_ref)
{
    struct Node *end = *head_ref;
    struct Node *prev = NULL;
    struct Node *curr = *head_ref;

    while(end->next != NULL)
    {
        end = end->next;
    }
    struct Node *new_end = end;

    while(curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }

    if(curr->data % 2 == 0)
    {
        *head_ref = curr;
        while(curr != end)
        {
            if(curr->data % 2 == 0)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                new_end->next = curr;
                new_end = curr;
                curr = prev->next;
            }
        }
    }
    else
    {
        prev = curr;
    }

    if(new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
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
    push(&head, 17);
    push(&head, 15);
    push(&head, 8);
    push(&head, 12);
    push(&head, 10);
    push(&head, 5);
    push(&head, 4);
    push(&head, 1);
    push(&head, 7);
    push(&head, 6);
    printf("Before -\n");
    printList(head);
    printf("\nAfter - \n");
    segregateEvenOdd(&head);
    printList(head);
    return 0;
}

