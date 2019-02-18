def rearrange(arr, n):
    arr_copy = arr
    even_pos = int(n/2)
    odd_pos = n - even_pos
    arr_copy.sort()
    j = odd_pos - 1
    for i in range(0, n, 2):
        arr[i] = arr_copy[j]
        j = j - 1
    j = odd_pos
    for i in range(1, n, 2):
        arr[i] = arr_copy[j]
        j = j + 1
    
