def findK(arr, n, k):

    count_map = {}
    calc_k = 0
    for num in arr:
        if num in count_map:
            count_map[num] += 1
            if count_map[num] is k:
                return num
        else:
            count_map[num] = 1
    return -1

arr = [1,1,2,3,4]
value = findK(arr, len(arr), 2)
print(value)
