#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void insert_front(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert_after(struct Node* prev_node, int new_data)
{
    if(prev_node == NULL)
    {
        printf("The given previos node does not exists!");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insert_end(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_node;
}

void deleteNode(struct Node** head_ref, int key)
{
    struct Node* temp = *head_ref;

    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* n)
{
    while(n != NULL)
    {
        printf("%d", n->data);
        n = n->next;
    }
}

int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data =1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);

    return 0;
}

