import sys


n = int(input())
best=0
now=0
cnt=0
hills=list(map(int,input().split()))
for i in hills:
    if i>now:
        now=i
        if cnt>best:
            best=cnt
        cnt=0
    else:
        cnt+=1;
ans=max(cnt,best)
print(ans)