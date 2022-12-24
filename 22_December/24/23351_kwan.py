n,k,a,b=map(int,input().split())
bun = [k for _ in range(n)]
index=0
day=1
flag=True
while flag:
    index = bun.index(min(bun))
    for i in range(a):
        bun[index+i]+=b
    for i in range(len(bun)):
        bun[i]-=1
        if bun[i]==0:
            print(day)
            flag=False
            break
    day += 1