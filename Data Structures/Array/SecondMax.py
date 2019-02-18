import sys

def find_second_max(arr, n):
    first = second = -sys.maxsize
    for i in range(n):
        if arr[i] > first:
            first = arr[i]
        if arr[i] > second and arr[i] < first:
            second = arr[i]
    return second

print(find_second_max([12,34,1,10,22,1,5,6], 8))
