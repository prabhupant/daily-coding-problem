def union(arr1, arr2):
    s = set()
    for i in arr1:
        s.add(i)
    for i in arr2:
        s.add(i)
    print(s)

def intersection(arr1, arr2):
    s = set()
    for i in arr1:
        s.add(i)
    for i in arr2:
        if i in s:
            print(i, end=" ")

def union_without_hash(arr1, arr2):
    i, j = 0, 0
    m, n = len(arr1), len(arr2)
    while i < m and j < n:
        if arr1[i] < arr2[j]:
            print(arr1[i])
            i += 1
        elif arr1[i] > arr2[j]:
            print(arr2[j])
            j += 1
        else:
            print(arr2[j])
            j += 1
            i += 1
    while i < m:
        print(arr1[i])
        i += 1
    while j < n:
        print(arr2[j])
        j += 1

def intersection_without_hash(arr1, arr2):
    i, j = 0, 0
    m = len(arr1)
    n = len(arr2)
    while i < m and j < n:
        if arr1[i] == arr2[j]:
            print(arr[i])
            i += 1
            j += 1
        elif arr1[i] < arr2[j]:
            i += 1
        elif arr2[j] < arr1[i]:
            j += 1


arr1 = [7,1,5,2,3,6]
arr2 = [3,8,6,20,7]

union(arr1, arr2)
intersection(arr1, arr2)
