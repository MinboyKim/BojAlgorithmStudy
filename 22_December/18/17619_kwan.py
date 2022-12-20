import sys
def find(x):
    if parent[x] == x:
        return x
    else:
        return find(parent[x])
def union(x,y):
    x_root = find(x)
    y_root = find(y)
    if x_root<y_root:
        parent[y_root] = x_root
    else:
        parent[x_root] = y_root
n,q = map(int,sys.stdin.readline().split())
namoos = []
parent = [i for i in range(n+1)]
for i in range(1,n+1):
    x1,x2,y = map(int,sys.stdin.readline().split())
    namoos.append((x1,x2,i))
sorted_namoos = sorted(namoos,key=lambda x:x[0])
x,y,_ = sorted_namoos[0]
for i in range(1,len(sorted_namoos)):
    nx,ny,_ = sorted_namoos[i]
    if nx<=y:
        union(sorted_namoos[i-1][-1],sorted_namoos[i][-1])
        y = max(y,ny)
    else:
        x,y = nx,ny
for _ in range(q):
    a,b = map(int,sys.stdin.readline().split())
    if find(a) == find(b):
        print(1)
    else:
        print(0)