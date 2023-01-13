from collections import deque
n,m = map(int,input().split())
indegree = [0 for _ in range(n+1)]
visited = [False for _ in range(n+1)]
graph = [[] for _ in range(n+1)]
q = deque([])
ans = []
for _ in range(m):
    edge = list(map(int,input().split()))
    for i in range(1,edge[0]):
        graph[edge[i]].append(edge[i+1])
        indegree[edge[i+1]]+=1
for i in range(1,n+1):
    if indegree[i]==0:
        q.append(i)
while q:
    temp = q.popleft()
    ans.append(temp)
    for node in graph[temp]:
        indegree[node] -= 1
        if indegree[node]==0:
            q.append(node)
if len(ans)==n:
    print(*ans)
else:
    print(0)
