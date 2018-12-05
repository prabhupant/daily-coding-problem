#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void addToEmpty(struct Node **last_ref, int data)
{
    if(*last_ref != NULL)
    {
        printf("The list is not empty!");
        return;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    *last_ref = new_node;
    (*last_ref)->next = new_node;
}

void insertFront(struct Node **last_ref, int data)
{
    if(*last_ref == NULL)
    {
        addToEmpty(&*last_ref, data);
        return;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*last_ref)->next;
    (*last_ref)->next = new_node;
}

void insertAfter(struct Node **last_ref, int key, int data)
{
    if(*last_ref == NULL)
    {
        printf("The list is empty!");
        return;
    }
    struct Node *new_node;
    struct Node *curr = (*last_ref)->next;
    do
    {
        if(curr->data == key)
        {
            new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = data;
            new_node->next = curr->next;
            curr->next = new_node;
            if(curr == *last_ref)
            {
                *last_ref = new_node;
            }
            return;
        }
        curr = curr->next;
    }while(curr != (*last_ref)->next);
    printf("The node is not present in the list!");
}

void insertEnd(struct Node **last_ref, int data)
{
    if(*last_ref == NULL)
    {
        addToEmpty(&*last_ref, data);
        return;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*last_ref)->next;
    (*last_ref)->next = new_node;
    *last_ref = new_node;
}

void printList(struct Node *last)
{
    if(last == NULL)
    {
        printf("The list is empty!");
        return;
    }
    struct Node *curr = last->next;
    do
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }while(curr != last->next);
}

void checkCircular(struct Node *last)
{
    if(last == NULL)
    {
        printf("The list is circular");
        return;
    }
    struct Node *curr = last;
    while(curr != NULL && curr != last)
    {
        curr = curr->next;
    }
    if(last == curr)
    {
        printf("The list is circular");
    }
    else
    {
        printf("The list is not circular");
    }
}

int main()
{
    struct Node *head = NULL;
    insertEnd(&head, 4);
    insertEnd(&head, 3);
    insertEnd(&head, 2);
    insertEnd(&head, 1);
    printf("The list is : \n");
    printList(head);
    checkCircular(head);
    return 0;
}

