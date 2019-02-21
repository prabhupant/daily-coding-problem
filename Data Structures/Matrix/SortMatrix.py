def sort_matrix(mat):
    temp = []
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            temp.append(mat[i][j])
    temp.sort()
    k = 0
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            mat[i][j] = temp[k]
            k += 1
    print(mat)
mat = [ [5,4,7], [1,3,8], [2,9,6] ] 
sort_matrix(mat)
