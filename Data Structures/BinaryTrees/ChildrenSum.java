class ChildrenSum
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

    static boolean checkChildrenSum(Node root)
    {
        int left_data = 0, right_data = 0;
        if(root == null || (root.left == null && root.right == null))
            return true;
        else
        {
            if(root.left != null)
                left_data = root.left.data;
            if(root.right != null)
                right_data = root.right.data;
            if( (root.data == left_data + right_data) && (checkChildrenSum(root.left)) && checkChildrenSum(root.right) )
                return true;
            else
                return false;
        }
    }
}


