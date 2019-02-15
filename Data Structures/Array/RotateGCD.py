def gcd(a, b):
    if b == a:
        return a
    else:
        return gcd(b, b%a)

def print_array(arr, size):
    for i in range(size):
        print("{}".format(arr[i]), end=" ")

def left_rotate(arr, d, n):
    for i in range(gcd(n, d)):
        temp = arr[i]
        j = i
        while 1:
            k = j + d
            if k >= n:
                k = k - n
            if k == i:
                break
            arr[j] = arr[k]
            j = k
        arr[j] = temp

arr = [1,2,3,4,5,6,7,8,9,10,11,12]
left_rotate(arr, 3, 12)
print_array(arr, 12)
