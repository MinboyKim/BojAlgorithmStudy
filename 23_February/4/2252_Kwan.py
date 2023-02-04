import sys
from collections import deque
input = sys.stdin.readline
def topological_sort():
    ans = []
    q = deque()
    for i in range(1,n+1):
        if indegree[i] == 0:
            q.append(i)
    while q:
        temp = q.popleft()
        ans.append(temp)
        for node in graph[temp]:
            indegree[node]-=1
            if indegree[node] == 0:
                q.append(node)
    print(*ans)
n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]
indegree=[0 for _ in range(n+1)]
for _ in range(m):
    start,dest = map(int,input().split())
    graph[start].append(dest)
    indegree[dest]+=1
topological_sort()




