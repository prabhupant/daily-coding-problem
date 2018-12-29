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
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
}

int getHeight(struct Node* root)
{
    if(root == NULL)
        return 0;
    int lheight = getHeight(root->left);
    int rheight = getHeight(root->right);
    return (lheight > rheight ? lheight + 1 : rheight + 1);
}

void printSpiralWrapper(struct Node* root)
{
    if (root == NULL)
        return;
    int h = getHeight(root);
    int i;
    int flip = 1;
    for(int i = 1; i <= h; i++)
    {
        printLevel(root, h ,flip);
        flip = !flip;
    }
}

void printLevel(struct Node* root, int level, int flip)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        if(flip)
        {
            printGivenLevel(root->left, level - 1, flip);
            printGivenLevel(root->right, level - 1, flip);
        }
        else
        {
            printGivenLevel(root->right, level - 1, flip);
            printGivenLevel(root->left, level - 1, flip);
        }
    }
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal is : \n");
    printSpiral(root);
    return 0;
}

