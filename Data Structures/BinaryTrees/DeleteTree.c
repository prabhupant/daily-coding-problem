#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return(new_node);
}

void deleteTree(struct Node* node)
{
    if(node == NULL)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    printf("\nDeleting node : %d", node->data);
    free(node);
}

void printInorder(struct Node* root)
{
    if(root == NULL)
        return;
    printInorder(root->left);
    printf("%d, ", root->data);
    printInorder(root->right);
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printInorder(root);
    deleteTree(root->left);
    printInorder(root);
    return 0;
}

