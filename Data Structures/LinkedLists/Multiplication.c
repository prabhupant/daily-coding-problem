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

void printList(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

long multiply(struct Node *first, struct Node *second)
{
    int num1 = 0;
    int num2 = 0;
    while(first || second)
    {
        if(first)
        {
            num1 = num1 * 10 + first->data;
            first = first->next;
        }
        if(second)
        {
            num2 = num2 * 10 + second->data;
            second = second->next;
        }
    }
    return num1*num2;
}

int main()
{
    struct Node *first = NULL;
    struct Node *second = NULL;
    
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    printf("First list is : ");
    printList(first);

    push(&second, 4);
    push(&second, 8);
    printf("\nSecond list is : ");
    printList(second);

    printf("\nResult is : %ld", multiply(first, second));
    return 0;
}

