def search(arr, low, high, key):
    if low > high:
        return -1
    mid = (l+h) // 2
    if arr[mid] == key:
        return mid
    if arr[low] <= arr[mid]:
        if key >= arr[low] and key <= arr[mid]:
            return search(arr, l, mid-1, key)
        return search(arr, mid+1, h, key)
    if key >= arr[mid] and key <= arr[h]:
        return search(a, mid+1, h, key)
    return search(arr, l, mid-1, key)


