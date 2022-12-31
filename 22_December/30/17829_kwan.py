def pool(m):
    new_mat=[]
    for i in range(0,len(m),2):
        row=[]
        for j in range(0,len(m),2): #column-first indexing
            pool = [row[j:j+2] for row in m[i:i+2]]
            pool = sorted(sum(pool,[]))
            value = pool[2]
            row.append(value)
        new_mat.append(row)
    return new_mat
n = int(input())
mat = [list(map(int,input().split())) for _ in range(n)]
while True:
    mat = pool(mat)
    if len(mat)==1:
        print(*mat[0])
        break
