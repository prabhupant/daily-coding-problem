def minOp(arr, n):
    
    dict = {}
    for num in arr:
        if num in dict:
            dict[num] += 1
        else:
            dict[num] = 1

    s = set(dict)
    max_count = 0
    for num in s:
        if max_count < dict[num]:
            max_count = dict[num]

    return n - max_count

arr = [1,5,2,1,3,2,1]
n = len(arr)
print(minOp(arr,n))

