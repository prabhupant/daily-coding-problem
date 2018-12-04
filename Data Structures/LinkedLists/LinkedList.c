#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node* root)
{
    while(root != NULL)
    {
        printf(" %d ", root->data);
        root = root->next;
    }
}

void insertFront(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(struct Node* prev_node, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertEnd(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    struct Node* curr = *head_ref;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
    return;
}

void deleteNode(struct Node** head_ref, int key)
{
    struct Node* temp = *head_ref, *prev;
    
    if(*head_ref == NULL)
    {
        printf("The list is already empty!");
        return;
    }

    if(temp != NULL && temp->data ==key)
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
        return;
    prev->next = temp->next;
    free(temp);
}

void swapNodes(struct Node** head_ref, int x, int y)
{
    if(x == y)
        return;
    struct Node* prevX = NULL;
    struct Node* currX = NULL;
    while(currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }
    struct Node* prevY = NULL;
    struct Node* currY = NULL;
    while(currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if(currX == NULL || currY == NULL){
        return;
    }

    if(prevX != NULL)
    {
        prevX->next = currY;
    }
    else{
        *head_ref = currY;
    }

    if(prevY != NULL)
    {
        prevY->next = currX;
    }
    else
    {
        *head_ref = currX;
    }

    struct Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* curr = *head_ref;
    struct Node* next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head_ref = prev;
}

int main()
{
    struct Node* head = NULL;
    insertFront(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 5);
    insertAfter(head->next->next, 4);
    printList(head);

    return 0;
}

