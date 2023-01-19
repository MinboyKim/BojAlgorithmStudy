import sys,heapq
from collections import defaultdict
def dijkstra(start):
    pq = []
    heapq.heappush(pq,(0,start))
    while pq:
        cost,curr = heapq.heappop(pq)
        if distance[curr]>cost:
            continue
        for next_cost,next_node in graph[curr]:
            total_cost = cost+next_cost
            if distance[next_node]>total_cost:
                distance[next_node]=total_cost
                heapq.heappush(pq,(total_cost,next_node))
    return distance
n,m,x = map(int,sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]
MAX = sys.maxsize
longest_distance = -1
all_distances=defaultdict(list)
for _ in range(m):
    start,end,cost = map(int,sys.stdin.readline().split())
    graph[start].append((cost,end))
for i in range(1,n+1):
    distance = [MAX] * (n + 1)
    distance[i] = 0
    all_distances[i]=dijkstra(i)
for i in range(1,n+1):
    if i==x:
        continue
    student_distance = all_distances[i][x] + all_distances[x][i]
    longest_distance = max(student_distance,longest_distance)
print(longest_distance)
