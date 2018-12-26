class Node
{
    int data;
    int left, right;

    public Node(int item)
    {
        data = item;
        left = right = null;
    }
}

class BinaryTree
{
    Node root;

    void morris(Node root)
    {
        Node curr, pre;

        if (root == null)
            return;
        curr = root;
        while(curr != null)
        {
            if(curr.left == null)
            {
                System.out.println(curr.data + " ");
                curr = curr.right;
            }
            else
            {
                pre = curr.left;
                while(pre.right != null && pre.right != curr)
                {
                    pre = pre.right;
                }
                if(pre.right == null)
                {
                    pre.right == curr;
                    curr = curr.left;
                }
                else
                {
                    pre.right = null;
                    System.out.println(current.data + " ");
                    curr = curr.right;
                }
            }
        }
    }
}


