import sys
n,m,k = map(int,sys.stdin.readline().split())
a = [0]
for _ in range(n):
    a.append(int(sys.stdin.readline()))
dp=[0 for _ in range(n+1)]
dp[1] = k
for i in range(2,n+1):
    minV=maxV=a[i]
    dp[i] = dp[i-1]+k
    for size in range(2,min(m,i)+1):
        j = i-size+1
        minV,maxV = min(minV,a[j]),max(maxV,a[j])
        box = k+size*(maxV-minV)
        dp[i] = min(dp[i],dp[j-1]+box)
print(dp[n])
