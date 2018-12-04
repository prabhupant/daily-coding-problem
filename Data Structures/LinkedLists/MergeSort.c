#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void mergeSort(struct Node **head_ref)
{
    struct Node *head = *head_ref;
    struct Node *a;
    struct Node *b;

    if(head == NULL || head->next == NULL)
        return;
    frontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *head_ref = sortedMerge(a, b);
}

struct Node* sortedMerge(struct Node *a, struct Node *b)
{
    struct Node *result = NULL;
    if(a == NULL)
        return(b);
    else if(b == NULL)
        return(a);

    if(a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return(result);
}

void frontBackSplit(struct Node *source, struct Node **frontRef, struct Node **backref)
{
    struct Node *fast;
    struct Node *slow;
    slow = source;
    fast = source->next;
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

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
    new_node->data = new _data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main()
{
    struct Node *res = NULL;
    struct Node *a = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
    mergeSort(&a);
    printf("Sorted Linked List is : \n");
    printList(a);
    return 0;
}

