def maxDistance(arr, n):

    mp = {}
    max_dist = 0
    for i in range(n):
        if arr[i] not in mp.keys():
            mp[arr[i]] = i
        else:
            max_dist = max(max_dist, i - mp[arr[i]])
    return max_dist

