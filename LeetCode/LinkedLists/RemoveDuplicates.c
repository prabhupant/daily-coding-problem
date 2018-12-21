/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head == NULL)
        return head;                        // returns NULL
    
    struct ListNode *current = head;        // save head in current
    struct ListNode *c_next = head->next;   // c_next points to current's next
    
    while(current->next != NULL)
    {
        if(current->val == c_next->val)
        {
            current->next = c_next->next;
            free(c_next);
            c_next = current->next;
        }
        else
        {
            current = c_next;
            c_next = current->next;
        }
    }
    
    return head;
}
