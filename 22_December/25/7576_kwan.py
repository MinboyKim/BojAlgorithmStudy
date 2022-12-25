from collections import deque
def findTomatoes():
    tomato=deque()
    for i in range(n):
        for j in range(m):
            if box[i][j]==1:
                tomato.append((i,j))
    return tomato
def checkTomato():
    max_num=0
    for i in range(n):
        for j in range(m):
                max_num=max(max_num,box[i][j])
    return max_num
def bfs(tomato,box):
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    while tomato:
        x,y = tomato.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<=nx<n and 0<=ny<m:
                if box[nx][ny]==0:
                    box[nx][ny] = box[x][y]+1
                    tomato.append((nx,ny))
    return checkTomato()-1
m,n = map(int,input().split())
box = [list(map(int,input().split())) for _ in range(n)]
tomato = findTomatoes()
days = bfs(tomato,box)
if [0 for i in range(n) for j in range(m) if box[i][j]==0]:
    print(-1)
else:
    print(days)
