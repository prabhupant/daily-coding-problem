import java.util.*;

class Node
{
    int data;
    Node left, right;

    public Node(int item)
    {
        data = item;
        left = right = null;
    }
}

class BinaryTree
{
    Node root;

    void printSpiral(Node node)
    {
        if(node == null)
            return;

        Stack<Node> s1 = new Stack<Node>();
        Stack<Node> s2 = new Stack<Node>();

        s1.push(node);
        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty())
            {
                Node temp = s1.peek();
                s1.pop();
                System.out.println(temp.data + " ");
                if(temp.right != null)
                    s2.push(temp.right);
                if(temp.left != null)
                    s2.push(temp.left);
            }
            while(!s2.empty())
            {
                Node temp = s2.peek();
                s2.pop();
                System.out.println(temp.data + " ");
                if(temp.left != null)
                    s1.push(temp.left);
                if(temp.right != null)
                    s1.push(temp.right);
            }
        }
    }

    public static void main(String args[])
    {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
    }
}

