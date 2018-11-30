#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct node* left;
    struct node* right;
}

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct Node* search(struct Node* root, int key)
{
    if(root == NULL || root->data == key)
    {
        return root;
    }
    if(root->key < key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

struct Node* insert(struct Node* root, int key)
{
    if(root == NULL)
        return newNode(key);
    if(key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if(key > root->key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->key);
        inorder(root->right);
    }
}

