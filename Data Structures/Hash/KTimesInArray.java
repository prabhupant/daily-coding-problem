import java.util.HashMap;

class KTimesInArray
{
    static int countK(int arr[], int n, int k)
    {
        HashMap<Integer, Integer> count_map = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++)
        {
            if(count_map.get(arr[i]) != null)
            {
                count_map.put(arr[i], count_map.get(arr[i])+1);
                if(count_map.get(arr[i]) == k)
                    return arr[i];
            }
            else
            {
                count_map.put(arr[i], 1);
            }
        }
        return -1;
    }

    public static void main(String args[])
    {
        int arr[] = {1,7,4,3,4,8,7};
        int n = arr.length;
        int k =2;
        System.out.println(countK(arr, n, k));
    }
}
