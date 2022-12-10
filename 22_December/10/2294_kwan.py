n,k=map(int,input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))
coins.sort()
dp=[100000000 for _ in range(k+1)]
dp[0]=0
for coin in coins:
    for i in range(coin,k+1):
        dp[i]=min(dp[i],dp[i-coin]+1)
print(dp[k]) if dp[k]!=0 and dp[k]!=100000000 else print(-1)

