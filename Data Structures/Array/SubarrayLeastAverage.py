def find_average(arr, n, k):
    if n < k:
        return 0
    res_index = 0
    curr_sum = 0
    for i in range(k):
        curr_sum += arr[i]

    min_sum = cur_sum
    for i in range(k, n):
        curr_sum += arr[i] + arr[i-k]
        if curr_sum < min_sum:
            min_sum = curr_sum
            res_index = i - k + 1

