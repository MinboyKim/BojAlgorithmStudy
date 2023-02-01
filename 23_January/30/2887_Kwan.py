import sys
import heapq
input = sys.stdin.readline
n = int(input())
graph = [[]*(n) for _ in range(n)]
visited = [False]*n
x_edge = []
y_edge = []
z_edge = []
for i in range(n):
    x,y,z = map(int,input().split())
    x_edge.append((x,i))
    y_edge.append((y,i))
    z_edge.append((z,i))
x_edge.sort(key = lambda x:x[0])
y_edge.sort(key = lambda x:x[0])
z_edge.sort(key = lambda x:x[0])
for i in range(1,n):
    graph[x_edge[i][1]].append((x_edge[i][0]-x_edge[i-1][0],x_edge[i-1][1]))
    graph[x_edge[i-1][1]].append((x_edge[i][0] - x_edge[i - 1][0], x_edge[i][1]))
    graph[y_edge[i][1]].append((y_edge[i][0]-y_edge[i-1][0],y_edge[i-1][1]))
    graph[y_edge[i-1][1]].append((y_edge[i][0] - y_edge[i - 1][0], y_edge[i][1]))
    graph[z_edge[i][1]].append((z_edge[i][0]-z_edge[i-1][0],z_edge[i-1][1]))
    graph[z_edge[i-1][1]].append((z_edge[i][0] - z_edge[i - 1][0], z_edge[i][1]))
visited[0] = 1
pq = []
for node in graph[0]:
    heapq.heappush(pq,node)
ans=0
while pq:
    temp = heapq.heappop(pq)
    if visited[temp[1]]:
        continue
    visited[temp[1]] = True
    ans+=temp[0]
    for node in graph[temp[1]]:
        heapq.heappush(pq,node)
print(ans)
