def rotate_by_one(arr, n):
    temp = arr[0]
    for i in range(n-1):
        arr[i] = arr[i+1]
    arr[n-1] = temp

def left_rotate(arr, d, n):
    for i in range(d):
        rotate_by_one(arr, n)

def print_array(arr, size):
    for i in range(size):
        print("{},".format(arr[i]),end=" ")

d = int(input("enter the value of d : "))
n = int(input("Enter the size of the array : "))
arr = []
for i in range(n):
    arr.append(int(input("Enter the element of the array : ")))
print("before")
print_array(arr, n)
print("after")
left_rotate(arr, d, n)
print_array(arr, n)
