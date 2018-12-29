class FoldableTree
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

    static boolean isFoldable(Node root)
    {
        if(root == null)
            return true;
        return isFoldableUtil(root.left, root.right);
    }

    static boolean isFoldableUtil(Node n1, Node n2)
    {
        if (n1 == null && n2 == null)
            return true;
        if (n1 == null || n2 == null)
            return false;
        return isFoldableUtil(n1.left, n2.right) && isFoldableUtil(n1.right, n2.left);
    }
}

