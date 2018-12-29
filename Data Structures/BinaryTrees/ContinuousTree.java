import java.util.*;

class ContinuousTree
{
    static class Node
    {
        int data;
        Node left, right;
        
        public Node(int data)
        {
            this.data = data;
            this.left = this.right = null;
        }
    }

    static boolean checkContinuous(Node node)
    {
        if(node == null)
            return true;
        if(node.left == null && node.right == null)
            return true;
        if(node.left == null)
            return (Math.abs(node.data - node.right.data) == 1) && checkContinuous(node.right);
        if(node.right == null)
            return (Math.abs(node.data - node.left.data) == 1) && checkContinuous(node.left);

        return Math.abs(node.data - node.left.data) == 1 &&
            Math.abs(node.data - node.right.data) == 1 &&
            checkContinuous(node.left) &&
            checkContinuous(node.right);
    }

    public static void main(String args[])
    {
        Node root = new Node(3);
        root.left = new Node(2);
        root.right = new Node(4);
        root.left.left = new Node(1);
        root.left.right = new Node(3);
        root.right.right = new Node(5);
        if(checkContinuous(root))
            System.out.println("yes");
        else
            System.out.println("no");
    }
}

