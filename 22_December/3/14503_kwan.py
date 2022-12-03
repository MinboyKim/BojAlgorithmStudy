direction = [0,1,2,3]
dx = [-1,0,1,0]
dy = [0,-1,0,1]
n,m = map(int,input().split())
r,c,d = map(int,input().split())
if d==1:
    d=3
elif d==3:
    d=1
room = [list(map(int,input().split())) for _ in range(n)]
count=0
while True:
    if room[r][c]==0:
        room[r][c]=2
        count+=1
    flag = False # 0->3, 1->0, 2->1 3->2
    for _ in range(4):#turn and check
        d = direction[(d+1)%4]
        nr = r+dx[d]
        nc = c+dy[d]
        if 0<=nr<n and 0<=nc<m:
            if room[nr][nc]==0:
                r = nr
                c = nc
                flag = True
                break
    if flag == False: #nowhere to clean
        nr = r-dx[d]
        nc = c-dy[d]
        if 0<=nr<n and 0<=nc<m:
            if room[nr][nc] == 1:
                break
            else:
                r = nr
                c = nc
        else:
            break
print(count)

