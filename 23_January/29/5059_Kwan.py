import sys
def mul(a,b,n,m):
    res = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                res[i][j] += a[i][k]*b[k][j]
            res[i][j] %=m
    return res
def pow(a,b,n,m):
    if b==1:
        return a
    else:
        temp = pow(a,b//2,n,m)
        if b%2 == 0:
            return mul(temp,temp,n,m)
        else:
            return mul(mul(temp,temp,n,m),a,n,m)
while True:
    n,m,p = map(int,sys.stdin.readline().split())
    if n==0:
        break
    mat = []
    for _ in range(n):
        mat.append(list(map(int,sys.stdin.readline().split())))
    result = pow(mat,p,n,m)
    for row in result:
        temp = list(map(str,row))
        print(' '.join(temp).strip())
    print()
