import sys,heapq
def topological_sort():
    ans=[]
    q = []
    for i in range(1,n+1):
        if indegree[i]==0:
            heapq.heappush(q,i)
    while q:
        temp = heapq.heappop(q)
        ans.append(temp)
        for node in graph[temp]:
            indegree[node]-=1
            if indegree[node]==0:
                heapq.heappush(q,node)
    print(*ans)
input = sys.stdin.readline
n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]
indegree = [0]*(n+1)
for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    indegree[b]+=1
topological_sort()
