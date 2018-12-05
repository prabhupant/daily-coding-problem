#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node *last)
{
    if(last == NULL)
    {
        printf("The list is empty!");
        return;
    }

    struct Node *curr = last->next;
    while(curr != last)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void addToEmpty(struct Node **last_ref, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
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
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*last_ref)->next;
    (*last_ref)->next = new_node;
}

void insertAfter(struct Node **last_ref, int key, int data)
{
    if(*last_ref == NULL)
        printf("The list is empty!");
    struct Node *new_node, *curr;
    curr = (*last_ref)->next;
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
        return addToEmpty(&*last_ref, data);
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*last_ref)->next;
    (*last_ref)->next = new_node;
    *last_ref = new_node;
}

void exchange(struct Node **last_ref)
{
    struct Node *first = (*last_ref)->next;
    (*last_ref)->next = first->next;
    first->next = *last_ref;
    *last_ref = first;
}

int main()
{
    struct Node *last = NULL;
    addToEmpty(&last, 3);
    insertFront(&last, 2);
    insertFront(&last, 1);
    insertEnd(&last, 4);
    insertEnd(&last, 6);
    insertAfter(&last, 5, 4);
    printList(last);
    printf("\nAfter swapping : \n");
    exchange(&last);
    printList(last);
    return 0;
}

