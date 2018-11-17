#Given the mapping a = 1, b =2, ... z= 26, and an encoded message, count the number of ways it can be decoded
#For example, the message '111' would give 3


class Recursive:

    def helper(data, k):
        if k == 0:
            return 1

        s = data.length - k
        if data[s] == '0':
            return 0

        result = helper(data, k-1)

        if k >= 2 and int(data[s:s+2]) <= 26:
            result += helper(data, k - 2)
        return result

    def num_ways(data):
        return helper(data, data.length)

class Dynamic:

    def helper_dp(data, k, memo):
        if k == 0:
            return 1

        s = data.length - k
        if data[s] == '0':
            return 0

        if memo[k] != null:
            return memo[k]

        result = helper_dp(data, k - 1, memo)
        if k >= 2 and int(data[s:s+2]) <= 26:
            result += helper_dp(data, k -2, memo)
        memo[k] = result
        return result

    def num_ways_dp(data):
        memo = new int[data.length + 1]
        return helper_dp(data, data.length, memo)
