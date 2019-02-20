def dutch(arr, n):
    low, mid, high = 0, 0, n-1
    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif a[mid] == 1:
            mid += 1
        else:
            a[high], a[mid] = a[mid], a[high]
            high -= 1

