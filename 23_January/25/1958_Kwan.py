a = list(input())
b = list(input())
c = list(input())
def lcs(a,b,c):
    p = len(a)
    q = len(b)
    r = len(c)
    dp =[[[0 for _ in range(r+1)] for _ in range(q+1)] for _ in range(p+1)]
    for i in range(1,p+1):
        for j in range(1,q+1):
            for k in range(1,r+1):
                if a[i-1]==b[j-1] and b[j-1]==c[k-1]:
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1
                else:
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1])
    return dp[-1][-1][-1]
print(lcs(a,b,c))