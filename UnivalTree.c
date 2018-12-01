#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int count = 0;

struct Node
{
    int data;
    struct Node *right, *left;
};

struct Node* newNode(int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool countUnivalRec(struct Node *root)
{
    if(root == NULL)
        return false;

    bool left = countUnivalRec(root->left);
    bool right = countUnivalRec(root->right);

    if(left == false || right == false)
    {
        return false;
    }
    if(root->right && root->data != root->left->data)
    {
        return false;
    }
    if(root->left && root->data != root->right->data)
    {
        return false;
    }
    count++;
    return true;
}

int countUnival(struct Node* root)
{
    countUnivalRec(root);
    return count;
}

int main()
{
    struct Node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(0);
    root->right->right = newNode(0);
    root->right->left = newNode(1);
    root->right->left->right = newNode(1);
    root->right->left->right->right = newNode(1);
    int result = countUnival(root);
    printf("The number of unival trees are : %d", result);
    return 0;
}

