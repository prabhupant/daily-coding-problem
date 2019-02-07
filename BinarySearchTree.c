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
    if(root->data < key)
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
    if(key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if(key > root->data)
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
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

int main()
{
    printf("Constructing the BST...");
    struct Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    inorder(root);
    return 0;
}

