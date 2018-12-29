import java.util.Queue;
import java.util.LinkedList;

class MirrorTree
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

    void levelOrder(Node root)
    {
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);
        while(!queue.isEmpty())
        {
            Node temp = queue.poll();
            System.out.println(temp.data + " ");
            if (temp.left != null)
                queue.add(temp.left);
            if(temp.right != null)
                queue.add(temp.right);
        }
    }

    Node mirror(Node node)
    {
        if(root == null)
            return node;

        Node left = mirror(node.left);
        Node right = mirror(node.right);
        node.left = right;
        node.right = left;
        return node;
    }
}

