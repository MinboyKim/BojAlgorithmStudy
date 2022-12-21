from collections import deque
n,m,k=map(int,input().split())
matrix = [[False for _ in range(m)] for _ in range(n)]
for _ in range(k):
    a,b=map(int,input().split())
    matrix[a-1][b-1]=True
queue = deque()
dx = [-1,1,0,0]
dy = [0,0,-1,1]
maxVal=0
tempVal=0
for i in range(n):
    for j in range(m):
        if matrix[i][j]:
            tempVal=0
            queue.append((i,j))
            matrix[i][j] = False
            while queue:
                x,y=queue.popleft()
                tempVal+=1
                for t in range(4):
                    nx,ny = x+dx[t],y+dy[t]
                    if 0<=nx<n and 0<=ny<m:
                        if matrix[nx][ny]:
                            matrix[nx][ny] = False
                            queue.append((nx,ny))
            maxVal = max(maxVal,tempVal)
print(maxVal)

