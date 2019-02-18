def mult(arr, n):
    temp = []
    for i in arr:
        temp.append(i)
    for i in range(n):
        if i == 0:
            temp[i] = arr[i] * arr[i+1]
        elif i == n-1:
            temp[i] = arr[i] * arr[i-1]
        else:
            temp[i] = arr[i-1] * arr[i+1]
    print(temp)

def mult_improved(arr, n):
    if n <= 1:
        return
    prev = arr[0]
    arr[0] = arr[0] * arr[1]
    for i in range(1, n-1):
        curr = arr[i]
        arr[i] = prev * arr[i+1]
        prev = curr
    arr[n-1] = prev * arr[n-1]
    print(arr)

arr = [2,3,4,5,6]
mult(arr, len(arr))
mult_improved(arr, len(arr))
