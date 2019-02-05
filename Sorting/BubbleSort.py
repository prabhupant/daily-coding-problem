def bubbleSort(arr):
    for i in range(len(arr) - 1):
        for j in range(i, len(arr)):
            if arr[j] < arr[i]:
                arr[i], arr[j] = arr[j], arr[i]

arr = [5,4,7,2,5,7,5,3,4,5,6,78,9]
bubbleSort(arr)
print(arr)
