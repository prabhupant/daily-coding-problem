def gcd(a, b):
    if b == a:
        return a
    else:
        return gcd(b, b%a)

def left_rotate(arr, k, n):
    for i in range(gcd(n, k)):
        temp = arr[i]
        j = i
        while 1:
            d = j + k
            if d >= n:
                d == d - n
            if d == i:
                break
            arr[j] = arr[d]
            j = d
        arr[j] = temp

def rotate_matrix_row(mat, k):
    r = len(mat)
    for i in range(r):
        left_rotate(mat[i], k , len(mat[i][0]))
    print(mat)

matrix = [ [1,2,3],[4,5,6],[7,8,9] ]
rotate_matrix_row(matrix, 2)
