def select_activity(s, f):
    print("The activities are : ")
    i = 0
    n = len(f)
    print(i)
    for j in range(n):
        if s[j] >= f[i]:
            print(j)
            i = j

s = [1,3,0,5,8,5]
f = [2,4,6,7,9,9]
select_activity(s, f)
