import sys

def printClosest(arr1, arr2, m, n, x):
    diff = sys.maxsize

    l = 0
    r = n-1
    while(l < m and r >= 0):
        if abs(arr1[l] + arr2[r] - x) < diff:
            res_l = l
            res_r = r
            diff = abs(arr1[l] + arr2[r] - x)

        if arr1[l] + arr2[r] > x:
            r = r - 1
        else:
            l = l + 1

    print("The closest pair i [", arr1[res_l], ", ", arr2[res_r],"]")


