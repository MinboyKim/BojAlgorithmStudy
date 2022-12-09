def findMaximumSquare(matrix,dp,n,m):
    ans=0
    for i in range(n):
        if 1 in matrix[i]:
            ans=1
            break
    for i in range(1,n):
        for j in range(1,m):
            if matrix[i][j]:
                dp[i][j] = min(matrix[i-1][j],matrix[i-1][j-1],matrix[i][j-1])+1
            ans = max(ans,dp[i][j])
    return ans
while True:
    n,m = map(int,input().split())
    if n == 0 and m == 0:
        break
    matrix = []
    for _ in range(n):
        matrix.append(list(map(int,input().split())))
    dp=matrix
    ans = findMaximumSquare(matrix,dp,n,m)
    print(ans)
