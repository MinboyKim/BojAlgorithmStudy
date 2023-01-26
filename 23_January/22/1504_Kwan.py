import sys,heapq
INF = int(1e9)
n,e = map(int,sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]
for _ in range(e):
    a,b,c = map(int,sys.stdin.readline().split())
    graph[a].append((c,b))
    graph[b].append((c,a))
v1,v2 = map(int,sys.stdin.readline().split())
def solve(start_node,end_node):
    q = []
    heapq.heappush(q,(0,start_node))
    distance= [INF]*(n+1)
    distance[start_node]=0
    while q:
        cost,curr = heapq.heappop(q)
        if cost>distance[curr]:
            continue
        for next_cost,next_node in graph[curr]:
            total_cost = next_cost + cost
            if total_cost < distance[next_node]:
                distance[next_node]=total_cost
                heapq.heappush(q,(total_cost,next_node))
    return distance[end_node]
result = min(solve(1,v1)+solve(v1,v2)+solve(v2,n),solve(1,v2)+solve(v2,v1)+solve(v1,n))
print("-1" if result>=INF else result)
