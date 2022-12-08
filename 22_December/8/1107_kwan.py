nList = list(input().strip())
n = int("".join(nList))
m = int(input())
ans=abs(n-100)
def checkBroken(num):
    temp = list(str(num))
    for n in temp:
        if n in broken:
            return True
    return False
if n ==100:
    if m:
        input()
    print(0)
else:
    if m:
        broken = list(input().strip().split())
        for num in range(1000000):
            if not checkBroken(num):
                ans = min(ans,len(list(str(num)))+abs(n-num))
        print(ans)
    else:
        print(min(len(nList),abs(n-100)))
