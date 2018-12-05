#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void addToEmpty(struct Node **last_ref, int data)
{
    if(*last_ref != NULL)
    {
        printf("The list is not empty!");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    *last_ref = new_node;
    (*last_ref)->next = *last_ref;
}

void insertFront(struct Node **last_ref, int data)
{
    if(*last_ref == NULL)
    {
        addToEmpty(&*last_ref, data);
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*last_ref)->next;
    (*last_ref)->next = new_node;
    return;
}

void insertAfter(struct Node** last, int data, int item)
{
    if(last == NULL)
        printf("The list is empty!");
    struct Node *new_node, *curr;
    curr = (*last)->next;
    do
    {
        if(curr->data == item)
        {
            new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = data;
            new_node->next = curr->next;
            curr->next = new_node;

            if(curr == *last)
            {
                *last = new_node;
            }
            return;
        }
        curr = curr->next;
    }while(curr != (*last)->next);
    printf("The node is not present in the list!");
}

void insertEnd(struct Node **last, int data)
{
    if(*last == NULL)
        return addToEmpty(&*last, data);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*));
    new_node->data = data;
    new_node->next = (*last)->next;
    (*last)->next = new_node;
    *last = new_node;
}

void deleteNode(struct Node **last_ref, int data)
{
    if(*last_ref == NULL)
    {
        printf("The list is empty!");
        return;
    }
    struct Node *curr = (*last_ref)->next;
    struct Node *prev;
    while(curr != *last_ref && curr->data != data)
    {
        if(curr == (*last_ref) && curr->data != data)
        {
            printf("The required node is absent!");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    if(curr == *last_ref)
    {
        prev->next = (*last_ref)->next;
        *last_ref = prev;
        free(curr);
        return;
    }
    prev->next = curr->next;
    free(curr);
}

void printList(struct Node *last)
{
    struct Node* curr;
    if(last == NULL)
    {
        printf("The list is empty!");
        return;
    }
    curr = last->next;
    do
    {
        printf("%d \n", curr->data);
        curr = curr->next;
    }while(curr != last->next);
}

int main()
{
    struct Node* last = NULL;
    addToEmpty(&last, 3);
    insertFront(&last, 2);
    insertFront(&last, 1);
    insertEnd(&last, 4);
    insertEnd(&last, 6);
    insertAfter(&last, 5, 4);
    printList(last);
    printf("\nDeleting node 4 now...\nNew List - \n");
    deleteNode(&last, 4);
    printList(last);
    printf("\nDeleting node 1 now...\nNew List - \n");
    deleteNode(&last, 1);
    printList(last);
    printf("\nDeleting node 6 now...\nNew List - \n");
    deleteNode(&last, 6);
    printList(last);
    return 0;
}


