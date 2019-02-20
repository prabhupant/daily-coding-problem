def binary_search(arr, l, r, x):
    while l =< r:
        mid = l + (r-l)/2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            r = mid - 1 
        else:
            l = mid + 1
    return -1

def find_pos(arr, key):
    l = 0
    h = 1
    val = arr[0]
    while val < key:
        l = h
        h = 2*h
        val = arr[h]
    return binary_search(arr, l, h, key)



