#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void morrisTraversal(struct Node* root)
{
    struct Node *curr, *pre;
    if(root == NULL)
        return;
    curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            printf("%d ", curr->data);
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if(pre->right == NULL)
            {
                pre->right = curr;
                curr = curr.left;
            }
            else
            {
                pre->right = NULL;
                printf("%d ", curr->data);
                curr = curr->right;
            }
        }
    }
}

