#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;
    struct Node* next;
};

void detectAndRemoveLoop(struct Node* head)
{
    if(head == NULL || head->next == NULL)
        return;
    struct Node* slow = head;
    struct Node* fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while(fast && fast->next)
    {
        if(slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow == fast)
    {
        slow = head;
        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

