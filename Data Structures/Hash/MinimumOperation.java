import java.util.*;

class MinimumOperation
{
    static int minOp(int arr[], int n)
    {
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
        for(int i = 0; i < n; i++)
        {
            if(hash.containsKey(arr[i]))
                hash.put(arr[i], hash.get(arr[i]) + 1);
            else
                hash.put(arr[i], 1);
        }
        int max_count = 0;
        Set<Integer> s = hash.keySet();

        for(int i : s)
        {
            if(max_count < hash.get(i))
                max_count = hash.get(i);
        }

        return (n- max_count);
    }

    public static void main(String args[])
    {
        int arrr[] = {1,5,2,1,3,2,1};
        int n = arr.lenght;
        System.out.println(minOp(arr, n));
    }
}
}
