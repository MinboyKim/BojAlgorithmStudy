from collections import deque
n,k = map(int,input().split())
visited = [[0,0] for _ in range(500001)]
def bfs(n,k):
    q = deque([n])
    level = 0
    visited[n][0]=0
    while q:
        qsize = len(q)
        for i in range(qsize):
            temp = q.popleft()
            flag = (level+1)%2
            for point in [temp-1,temp+1,temp*2]:
                if point<0 or point>500000:
                    continue
                if visited[point][flag] == 0:
                    visited[point][flag] = level + 1
                    q.append(point)
        level+=1
if n==k:
    print(0)
else:
    bfs(n,k)
    sec = 0
    ans = -1
    for i in range(500001):
        k+=i
        if k>500000:
            break
        if visited[k][sec%2] <=sec:
            ans = sec
            break
        sec +=1
    print(ans)
