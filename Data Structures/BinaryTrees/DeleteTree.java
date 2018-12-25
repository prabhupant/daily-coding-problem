class Node 
{   
    int data;
    Node left; right;
    Node(int item)
    {    
        data = item;
        left = right = null;
    }
}

class BinaryTree
{
    Node root;
    
    void deleteTree(Node node)
    {
        root = null;
    }

    public static void main(String[] args)
    {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
    }
}

