from collections import deque
n,k = map(int,input().split())
visited = [0]*(100001)
def bfs(n,k):
    queue = deque([n])
    while queue:
        temp = queue.popleft()
        if temp==k:
            return visited[temp]
        for point in [temp-1,temp+1,2*temp]:
            if point<0 or point>100000:
                continue
            if not visited[point]:
                visited[point]=visited[temp]+1
                queue.append(point)
if n==k:
    print(0)
else:
    print(bfs(n,k))
