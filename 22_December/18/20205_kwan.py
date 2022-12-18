n,k = map(int,input().split())
bitmap = [list(map(int,input().split())) for _ in range(n)]
ans = [[0 for _ in range(n*k)] for _ in range(n*k)]
for i in range(n):
    for j in range(n):
        for t in range(j*k,j*k+k):
            for r in range(i*k,i*k+k):
                ans[r][t] = bitmap[i][j]
for row in ans:
    print(*row)
