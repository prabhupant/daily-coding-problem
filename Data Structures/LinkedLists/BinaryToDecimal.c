#include<stdio.h>
#include<stdlib.h>

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

void push(struct Node **head_ref, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int binaryToDecimal(struct Node* head)
{
    int res = 0;
    while(head != NULL)
    {
        res = (res << 1) + head->data;
        head = head->next;
    }
    return res;
}

int main()
{
    struct Node *head = NULL;
    push(&head,1);
    push(&head, 0);
    push(&head, 1);
    push(&head, 1);
    printf("The original list is : \n");
    printList(head);
    printf("\nThe decimal equivalent is : \n");
    int dec = binaryToDecimal(head);
    printf("%d", dec);
    return 0;
}

