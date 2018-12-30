class SumTree
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

    boolean checkSum(Node node)
    {
        
        if (node == null || (node.left == null && node.right == null))
            return true;
        int l = checkSum(node.left);
        int r = checkSum(node.right);
        if( node.data == l + r && checkSum(node.left) && checkSum(node.right) )
            return true;
        else
            return false;
    }
}

