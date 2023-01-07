import heapq
import sys
n,m=map(int,sys.stdin.readline().split())
pq=[]
village = [[] for _ in range(n+1)]
visit = [False for _ in range(n+1)]
for _ in range(m):
    a,b,dist = map(int,sys.stdin.readline().split())
    village[a].append((dist,b))
    village[b].append((dist,a))
visit[1]=True
for edge in village[1]:
    heapq.heappush(pq,edge)
ans=[]
while pq:
    temp = heapq.heappop(pq)
    if visit[temp[1]]:
        continue
    visit[temp[1]]=True
    ans.append(temp[0])
    for edge in village[temp[1]]:
        heapq.heappush(pq,edge)
    if len(ans)==n:
        break
print(sum(ans)-max(ans))