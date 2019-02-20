def find_single(arr, n):
    res = arr[0]
    for i in range(1,n):
        res = res ^ arr[i]
    return res

