#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head, int k)
{
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    int count = 0;
    while(curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL)
    {
        head->next = reverse(next, k);
    }
    return prev;
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node* head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("\nGiven Linked List \n");
    printList(head);
    head = reverse(head, 3);

    printf("\nReversed Linked List \n");
    printList(head);

    return 0;
}

