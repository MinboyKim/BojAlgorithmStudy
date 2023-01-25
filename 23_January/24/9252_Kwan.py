a = list(map(str,input()))
b = list(map(str,input()))
n = len(a)
m = len(b)
dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        if a[i-1]==b[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])
result = []
temp = dp[-1][-1]
x,y = n,m
while x>0 and y>0:
    if dp[x][y]==0:
        break
    if dp[x-1][y] == temp:
        x-=1
    elif dp[x][y-1]==temp:
        y-=1
    else:
        result.append(a[x-1])
        x-=1
        y-=1
        temp = dp[x][y]
print(dp[-1][-1])
print("".join(reversed(result)))
