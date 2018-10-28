def product(arr):
    left = []
    right = []
    for i in range(0, len(arr)):
        left.append(1)
        right.append(1)
    
    result = []
    for i in range(1, len(arr)):
        left[i] = left[i-1] * arr[i-1]
    
    for i in reversed(range(0, len(arr) - 1)):
        right[i] = right[i+1] * arr[i+1]
    
    for i in range(0, len(arr)):
        result.append(right[i] * left[i])
    print(result)

if __name__ == '__main__':
    x = int(input("Enter the number of elements of array"))
    lst = []
    for i in range(x):
        lst.append(int(input("number: ")))
    print("the answer is ")
    product(lst)


