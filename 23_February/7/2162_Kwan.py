import sys
input = sys.stdin.readline
def findRoot(node):
    if root[node]!=node:
        return findRoot(root[node])
    return root[node]
def union(x,y):
    nx,ny = findRoot(x),findRoot(y)
    if nx!=ny:
        root[ny] = nx
def ccw(x1,x2,x3,y1,y2,y3):
    temp = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)
    if temp>0:
        return 1
    elif temp==0:
        return 0
    else:
        return -1
def check(line1,line2):
    x1,y1,x2,y2 = line1
    x3,y3,x4,y4 = line2
    slope1 = ccw(x1,x2,x3,y1,y2,y3) * ccw(x1,x2,x4,y1,y2,y4)
    slope2 = ccw(x3,x4,x1,y3,y4,y1) * ccw(x3,x4,x2,y3,y4,y2)
    if slope1 == 0 and slope2 ==0:
        return (min(x1,x2)<=max(x3,x4) and min(x3,x4) <=max(x1,x2) and min(y1,y2) <=max(y3,y4) and min(y3,y4) <=max(y1,y2))
    else:
        return (slope1<=0) and (slope2<=0)
n = int(input())
root = [i for i in range(n)]
cord = [list(map(int,input().split())) for _ in range(n)]
for i in range(n):
    for j in range(i+1,n):
        if check(cord[i],cord[j]) and findRoot(i)!=findRoot(j):
            union(i,j)
for i in range(n):
    root[i] = findRoot(i)
print(len(list(set(root))))
print(root.count(max(root,key=root.count)))

