def print_spiral(arr, m, n):
    k = 0
    l = 0
    while k < m and l < n:
        for i in range(l, n):
            print(arr[k][i], end = " ")
        k += 1
        for i in range(k, m):
            print(arr[i][n-1], end = " ")
        n -= 1
        if k < m:
            for i in range(n-1, l-1, -1):
                print(a[m-1][i], end = " ")
            m -= 1
        if l < n:
            for i in range(m-1, k-1, -1):
                print(arr[i][l], end = " ")
            l += 1

