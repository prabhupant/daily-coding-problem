def first(arr, low , high):
    if high >= low:
        mid = low + (high - low)//2
        if (mid ==0 or arr[mid-1] == 0) and arr[mid] == 1:
            return mid
        elif arr[mid] == 0:
            return first(arr, mid+1, high)
        else:
            return first(arr, low, mid-1)
    return -1

def row_with_max_ones(mat):
    r = len(mat)
    c = len(mat[0])
    max_row_index = 0
    max_ = -1
    for i in range(r):
        index = first(mat[i], 0, c-1)
        if index != -1 and c - index > max_:
            max_ = c - index
            max_row_index = i
    return max_row_index


