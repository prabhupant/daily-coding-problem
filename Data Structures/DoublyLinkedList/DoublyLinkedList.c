#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertFront(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data)
{
    if(prev_node == NULL)
    {
        printf("The given previous node cannot be null!");
        return;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;
    
    if(new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}

void insertEnd(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;

    if(*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(struct Node **head_ref, struct Node* del)
{
    if(*head_ref == NULL || del == NULL)
        return;
    if(*head_ref == del)
    {
        *head_ref = del->next;
    }
    if(del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    if(del->prev != NULL)
    {
        del->prev->next = del->next;
    }
    free(del);
    return;
}

void reverse(struct Node **head_ref)
{
    struct Node *temp = NULL;
    struct Node *current = *head_ref;
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != NULL)
    {
        *head_ref = temp->prev;
    }
}

void printList(struct Node* head)
{
    struct Node* last;
    printf("Traversal in forward direction \n");
    while(head != NULL)
    {
        printf(" %d ", head->data);
        last = head;
        head = head->next;
    }
    printf("\nTraversal in reverse direction \n");
    while(last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

int main()
{
    struct Node* head = NULL;
    insertFront(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 4);
    insertAfter(head->next, 3);
    printList(head);
    insertEnd(&head, 5);
    deleteNode(&head, head->next->next->next->next);
    printf("\nAfter deleting the node : \n");
    printList(head);
    printf("\nNow reversing the list : \n");
    reverse(&head);
    printList(head);
    return 0;
}

