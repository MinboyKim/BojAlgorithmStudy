t = int(input())
for _ in range(t):
    x,y = map(int,input().split())
    dis = y - x
    n = 0
    while True:
        if dis<=n*(n+1):
            break
        n+=1
    if dis<=n**2:
        print(n*2-1)
    else:
        print(n*2)