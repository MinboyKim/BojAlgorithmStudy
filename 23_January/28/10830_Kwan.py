import sys
n,b = map(int,input().split())
matrix=[]
for _ in range(n):
    matrix.append(list(map(int,sys.stdin.readline().split())))
def mat_mul(a,b):
    res = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                res[i][j] +=a[i][k] * b[k][j] % 1000
    return res
def pow(a,b):
    if b==1:
        return a
    else:
        temp = pow(a,b//2)
        if b%2==0:
            return mat_mul(temp,temp)
        else:
            return mat_mul(mat_mul(temp,temp),a)
ans = pow(matrix,b)
for row in ans:
    for col in row:
        print(col%1000,end=" ")
    print()
