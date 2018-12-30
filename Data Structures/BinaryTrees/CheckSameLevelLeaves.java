class CheckSameLevelLeaves
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

    static class Leaf
    {
        int leafLevel = 0;
    }

    boolean check(Node root, myLevel)
    {
        int level = 0;
        return checkUtil(root, level, myLevel);
    }

    boolean checkUtil(Node node, int level, Leaf leafLevel)
    {
        if(node == null)
            return true;
        if(node.left == null && node.right == null)
        {
            if(leafLevel.leafLevel == 0)
            {
                leafLevel.leafLevel = level;
                return true;
            }
            return (level == leafLevel.leafLevel);
        }
        return checkUtil(node.left, level + 1, leafLevel) && checkUtil(node.right, level + 1, leafLevel);
    }

}

