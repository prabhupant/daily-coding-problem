#include<iostream>
#include<queue>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}

struct Node* newNode(int key)
{
    struct Node* new_node = new Node;
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;
}

void inorder(struct Node* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void insert(struct Node* temp, int key)
{
    queue<struct Node*> q;
    q.push(temp);
    
    //doing level order traversal until we find an empty space
    while(!q.empty())
    {
        struct Node* temp = q.front();
        q.pop();
        if(!temp->left)
        {
            temp->left = newNode(key);
            break;
        } else
        {
            q.push(temp->left);
        }

        if(!temp->right)
        {
            temp->right = newNode(key);
            break;
        } else
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    struct Node* root = newNode(10);
    return 0;
}


