n,k = map(int,input().split())
a = list(map(int,input().split()))
ans = 0
s,e=0,0
for i in range(n):
    if s<0:
        s = i
    if k|a[i] > k:
        ans = 0
        s = -1
        e = -1
    else:
        ans = a[i] | ans
        if ans == k:
            e = i
            break
if ans==k:
    s+=1
    e+=1
    print(s,e)
else:
    print(-1)
