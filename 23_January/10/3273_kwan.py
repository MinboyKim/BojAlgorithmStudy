n = int(input())
a = list(map(int,input().split()))
a.sort()
x = int(input())
lp,rp=0,len(a)-1
ans = 0
while lp<rp:
    if a[lp]+a[rp]>x:
        rp-=1
    elif a[lp]+a[rp]<x:
        lp+=1
    elif a[lp]+a[rp]==x:
        ans+=1
        rp-=1
print(ans)