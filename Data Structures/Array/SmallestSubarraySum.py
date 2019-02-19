def smallest_subarray(arr, n, sum_):
    curr_sum = 0
    start = 0
    i = 1
    curr_length = 0
    minsize = n + 1
    while i <= n:
        while curr_sum <= sum_ and i < n:
            curr_sum += arr[end]
            i += 1
        while curr_sum > sum_ and start < n:
            if i - start < minsize:
                minsize = i - start
            curr_sum -= arr[start]
            start += 1
        return minsize


