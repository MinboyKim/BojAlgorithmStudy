import sys
n = int(input())
m = int(input())
INF = int(1e9)
dist = [[INF]*(n+1) for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,n+1):
        if i==j:
            dist[i][j]=0
for _ in range(m):
    a,b,cost = map(int,sys.stdin.readline().split())
    dist[a][b]=min(dist[a][b],cost)
for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j])
for i in range(1,n+1):
    for j in range(len(dist[i])):
        if dist[i][j] == INF:
            dist[i][j] = 0
    print(*dist[i][1:])

