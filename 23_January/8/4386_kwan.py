import math
def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]
def union(x,y):
    x = find(x)
    y = find(y)
    if x==y:
        return
    if x<y:
        parent[y]=x
    else:
        parent[x]=y
n = int(input())
parent = [i for i in range(n+1)]
stars =[]
edges=[]
ans=0.0
for i in range(n):
    x,y = map(float,input().split())
    stars.append((x,y))
for i in range(n-1):
    for j in range(i+1,n):
        edges.append((math.sqrt((stars[i][0]-stars[j][0])**2+(stars[i][1]-stars[j][1])**2),i,j))
edges.sort()
for e in edges:
    cost,x,y=e
    if find(x)!=find(y):
        union(x,y)
        ans+=cost
print(round(ans,2))