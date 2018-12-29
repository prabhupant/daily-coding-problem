import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Vector;

public class DiagonalTraversal
{
    static class Node
    {
        int data;
        Node left;
        Node right;
        
        Node(int data)
        {
            this.data = data;
            left = null;
            right = null;
        }
    }

    static void diagonalPrintUtil(Node root, int d, HashMap<Integer, Vector<Integer>> diagnal_map)
    {
        if(root == null)
            return;
        Vector<Integer> k = diagonal_print.get(d);
        if (k == null)
        {
            k = new Vector<>();
            k.add(root.data);
        }
        else
        {
            k.add(root.data);
        }
        diagonal_map.put(d, k);
        diagonalPrintUtil(root.left, d+1, diagonal_map);
        diagonalPrintUtil(root.right, d, diagonal_map);
    }

    static void diagonalPrint(Node root)
    {
        HashMap<Integer, Vector<Integer>> diagonal_map = new HashMap<>();
        diagonalPrintUtil(root, 0, diagonal_map);
        System.out.println("diagonal - ");
        for(Entry<Integer, Vector<Integer>> entry : diagonalPrint.entrySet();)
        {
            System.out.println(entry.getValue());
        }
    }
}

