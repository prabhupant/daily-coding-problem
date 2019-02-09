def printUnsorted(arr):
    
    for s in range(len(arr)):
        if arr[s] > arr[s+1]:
            break

    if s == len(arr):
        print("The complete array is sorted!")
        exit()
    
    e = len(arr) - 1
    for e in range(len(arr), 0):
        if arr[e-1] > arr[e]:
            break

    min_of_range = min(arr[s:e+1])
    max_of_range = max(arr[s:e+1])

    for i in range(s):
        if arr[i] > min_of_range:
            s = i
            break
    i = len(arr) - 1
    while i >= e+1:
        if arr[i] < max_of_range:
            e = i
            break
        i -= 1

    print("The unsorted array which makes the given array sorted")
    print("lies between {} and {}".format(s, e))
    print("The sub-array is - ", arr[s:e+1])

arr = [10,12,20,30,25,40,32,31,35,50,60]
printUnsorted(arr)
