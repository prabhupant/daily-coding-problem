#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node* next;
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

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void zigZag(struct Node *head)
{
    bool flag = true;
    sturct Node *curr = head;
    while(curr->next != NULL)
    {
        if(flag)
        {
            if(current->data > current->next->data)
                swap(&current->data, &current->next->data);
        }
        else
        {
            if(current-> < current->next->data)
                swap(&current->data, &current->next->data);
        }
        current = current->next;
        flag = !flag;
    }
}

int main()
{
    struct Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 6);
    push(&head, 8);
    push(&head, 7);
    push(&head, 3);
    push(&head, 4);
    printf("Given linked list \n");
    printList(head);
    zigZag(head);
    printf("\nZig Zag linked list \n");
    printList(head);
    return 0;
}

