import sys
sys.setrecursionlimit(int(1e6))
input = sys.stdin.readline
def findRoot(node):
    if root[node]!= node:
        return findRoot(root[node])
    return root[node]
def union(x,y):
    nx,ny = findRoot(x),findRoot(y)
    if nx!=ny:
        root[ny] = nx
    else:
        return -1
n,m = map(int,input().split())
root = [i for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    if union(a,b) == -1:
        print(i+1)
        exit(0)
print(0)
