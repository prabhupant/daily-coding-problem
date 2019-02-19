def find_subarray(arr, n, sum_):
    curr_sum = arr[0]
    start = 0
    i = 1
    while i <= n:
        while curr_sum > sum_ and start < i-1:
            curr_sum -= arr[start]
            start += 1
        if curr_sum == sum_:
            print("Sum found between indexes {} and {}".format(start, i-1))
            return
        if i < n:
            curr_sum += arr[i]
        i += 1
    print("No subarray found")
    return

arr = [15,2,4,8,9,5,10,23]
sum_ = 23
find_subarray(arr, len(arr), sum_)
