def fix_array(arr):
    s = set()
    for i in arr:
        s.add(i)
    for i in range(len(arr)):
        if i in s:
            arr[i] = i
        else:
            arr[i] = -1

arr = [-1,-1,6,1,9,3,2,-1,4,-1]
fix_array(arr)
print(arr)
