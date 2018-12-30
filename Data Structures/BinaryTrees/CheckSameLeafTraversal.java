import java.util.*;
import java.lang.*;
import java.io.*;

class CheckSameLeafTraversal
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
        public boolean isLeaf()
        {
            return (left == null && right == null)
        }
    }
    
    static boolean isSame(Node root1, Node root2)
    {
        Stack<Node> s1 = new Stack<Node>();
        Stack<Node> s2 = new Stack<Node>();
        s1.push(root1);
        s2.push(root2);
        while(!s1.empty() || !s2.empty())
        {
            if(s1.empty() || s2.empty())
                return false;
            Node temp1 = s1.pop();
            while(temp1 != null && !temp1.isLeaf())
            {
                if(temp1.right != null)
                    s1.push(temp1.right);
                if(temp1.left != null)
                    s1.push(temp1.left);
                temp1 = s1.pop();
            }
            Node temp2 = s2.pop();
            while(temp2 != null && !temp2.isLeaf())
            {
                if(temp2.right != null)
                    s2.push(temp2.right);
                if(temp2.left != null)
                    s2.push(temp2.left);
                temp2 = s2.pop();
            }

            if(temp1 == null && temp2 != null)
                return false;
            if(temp1 != null && temp2 == null)
                return false;
            if(temp1!=null && temp2!=null)
                if(temp1.data != temp2.data)
                    return false;
            return true;
        }
    }
}

