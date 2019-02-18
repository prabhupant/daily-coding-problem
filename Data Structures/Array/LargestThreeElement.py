import sys

def print_largest_three(arr, n):
    if n < 3:
        print("Invalid input")
        return
    first = second = third = -sys.maxsize
    for i in range(0, n):
        if arr[i] > first:
            third = second
            second = first
            first = arr[i]
        elif arr[i] > second:
            third = second
            second = arr[i]
        elif arr[i] > third:
            third = arr[i]
    print("Three largest elements are ", first, second, third)

arr = [12,13,1,10,34,1]
print_largest_three(arr, len(arr))
