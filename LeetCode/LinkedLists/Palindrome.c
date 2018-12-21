/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reverse(struct ListNode **head_ref)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = *head_ref;
    struct ListNode *next;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head_ref = prev;
}

bool compareLists(struct ListNode *head1, struct ListNode *head2)
{
    struct ListNode *temp1 = head1;
    struct ListNode *temp2 = head2;
    while(temp1 && temp2)
    {
        if(temp1->val == temp2->val)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            return false;
        }
    }
    if(temp1 == NULL && temp2 == NULL)
    {
        return true;
    }
    return false;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow_ptr = head;
    struct ListNode *fast_ptr = head;
    struct ListNode *second_half = head;
    struct ListNode *prev_of_slow_ptr = head;
    struct ListNode *mid_node = NULL;
    bool res = true;
    
    if(head != NULL && head->next != NULL)
    {
        while(fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        if(fast_ptr != NULL)
        {
            mid_node = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL;
        reverse(&second_half);
        res = compareLists(head, second_half);
        reverse(&second_half);
        if(mid_node != NULL)
        {
            prev_of_slow_ptr->next = mid_node;
            mid_node->next = second_half;
        }
        else
        {
            prev_of_slow_ptr->next = second_half;
        }
        
    }
    return res;
}


