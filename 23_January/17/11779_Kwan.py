import sys,heapq
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
graph = [[] for _ in range(n+1)]
dist = [sys.maxsize]*(n+1)
for _ in range(m):
    start,end,cost = map(int,sys.stdin.readline().split())
    graph[start].append((cost,end))
start,end = map(int,sys.stdin.readline().split())
parents = [0]*(n+1)
def solve(start):
    pq = []
    heapq.heappush(pq, (0, start))
    dist[start] = 0
    while pq:
        cost, curr = heapq.heappop(pq)
        if dist[curr] < cost:
            continue
        for node in graph[curr]:
            next_dist, next_node = node[0], node[1]
            total_cost = next_dist + cost
            if total_cost < dist[next_node]:
                dist[next_node] = total_cost
                heapq.heappush(pq, (total_cost, next_node))
                parents[next_node] = curr
solve(start)
result = [end]
current = end
while current!=start:
    current = parents[current]
    result.append(current)
result.reverse()
print(dist[end])
print(len(result))
print(*result)
