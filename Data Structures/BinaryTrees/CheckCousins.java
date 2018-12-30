class CheckCousins
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

    int findLevel(Node root, Node node, int lev)
    {
        if(root == null)
            return 0;
        if(root == node)
            return lev;
        int l = level(node.left, node, lev + 1);
        if(l!=0)
            return l;
        return level(node.right, node, lev + 1);
    }

    boolean checkSibling(Node root, Node a, Node b)
    {
        if(root == null)
            return false;
        return( (root.left == a && root.right == b) || (root.left == b && root.right == a) || checkSibling(root.left, a, b) || checkSibling(root.right, a, b));
    }

    boolean checkCousin(Node root, Node a, Node b)
    {
        return( (findLevel(root, a, 1) == findLevel(root, b, 1)) && !checkSibling(root, a, b));
    }
}

