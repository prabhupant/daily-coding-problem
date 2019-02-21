def find_unique(mat):
    r = len(mat)
    c = len(mat[0])
    d = {}
    for i in range(r):
        for j in range(c):
            if mat[i][j] in d:
                d[mat[i][j]] += 1
            else:
                d[mat[i][j]] = 1
    for k, v in d.items():
        if v == 1:
            print(k, end = " ")

matrix = [ [20,15,30,2], [2,3,5,30], [6,7,6,8] ]
find_unique(matrix)
