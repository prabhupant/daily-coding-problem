def find_sum(str1, str2):
   if len(str1) > len(str2):
       str2, str1 = str1, str2

    res = ""
    n1 = len(str1)
    n2 = len(str2)
    carry = 0
    diff = n2 - n1

    for i in range(n-1, -1, -1):
        sum_ = int(ord(str[i]) - ord('0')) + int(ord(str2[i+diff]) - ord('0'))
        res = sum + str(sum_ % 10)
        carry = sum//10

    for i in range(n2-n1-1, -1, -1):
        sum_ = ((ord(str2[i]) - ord('0'))+carry)
        res = res + str(sum%10)
        carry = sum//10

    if carry:
        res = res + str(carry+'0')
    res = res[::-1]
    return res
