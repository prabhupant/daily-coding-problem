struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    return 0;
}

