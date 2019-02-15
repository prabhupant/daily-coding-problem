def reverse_array(arr, start, end):
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1

arr = [1,2,3,4,5]
reverse_array(arr, 0, 4)
print(arr)
