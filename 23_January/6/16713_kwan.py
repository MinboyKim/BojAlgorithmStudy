import sys
n,q=map(int,sys.stdin.readline().split())
an = list(map(int,sys.stdin.readline().split()))
prefix = [0]
for num in an:
    prefix.append(prefix[-1] ^ num)
ans=0
for _ in range(q):
    s,e=map(int,sys.stdin.readline().split())
    temp = prefix[e] ^ prefix[s-1]
    ans = ans ^ temp
print(ans)

