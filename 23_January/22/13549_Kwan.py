from collections import deque
n,k = map(int,input().split())
def solve(n,k):
    q = deque([n])
    visited = [0]*(100001)
    visited[n]=0
    while q:
        temp = q.popleft()
        if temp>100001:
            continue
        if temp==k:
            print(visited[k])
            return
        for node in (temp*2,temp-1,temp+1):
            if node>100000 or node<0:
                continue
            if visited[node]==0:
                if node == temp*2:
                    visited[node] = visited[temp]
                else:
                    visited[node] = visited[temp]+1
                q.append(node)
solve(n,k)