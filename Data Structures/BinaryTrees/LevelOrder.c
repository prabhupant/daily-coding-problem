#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data);
int getHeight(struct Node* root);
void printLevelOrder(struct Node* root);
void printGivenLevel(struct Node* root, int level);

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

int getHeight(struct Node* root)
{
    if(root == NULL)
        return 0;
    int lheight = getHeight(root->left);
    int rheight = getHeight(root->right);
    int height = lheight > rheight ? lheight + 1 : rheight + 1;
    return height;
}

void printLevelOrder(struct Node* root)
{
    int h = getHeight(root);
    int i;
    for(i = 1; i <= h; i++)
    {
        printGivenLevel(root, i);
    }
}

void printGivenLevel(struct Node* root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}


