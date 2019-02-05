def selectionSort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]      

arr = [4,2,5,1,7,3,7,4,5,67,43]
selectionSort(arr)
print(arr)
