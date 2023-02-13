import bisect
import sys
input = sys.stdin.readline
t = int(input())
n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
asum = [a[0]]*n
bsum = [b[0]]*m
for i in range(1,n):
    asum[i] = asum[i-1] + a[i]
for j in range(1,m):
    bsum[j] = bsum[j-1] + b[j]
a_subsum = []
b_subsum = []
for i in range(n):
    a_subsum.append(asum[i])
    for j in range(i):
        a_subsum.append(asum[i]-asum[j])
for i in range(m):
    b_subsum.append(bsum[i])
    for j in range(i):
        b_subsum.append(bsum[i]-bsum[j])
a_subsum.sort()
b_subsum.sort()
ans = 0
for i in range(len(a_subsum)):
    l = bisect.bisect_left(b_subsum,t-a_subsum[i])
    r = bisect.bisect_right(b_subsum,t-a_subsum[i])
    ans+= r-l
print(ans)