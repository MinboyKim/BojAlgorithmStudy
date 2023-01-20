from collections import deque
n,k = map(int,input().split())
def solve(n,k):
    visited = [-1]*100001
    q = deque([n])
    ans=0
    visited[n]=0
    while q:
        temp = q.popleft()
        if temp == k:
            ans += 1
            continue
        for node in (temp - 1, temp + 1, temp * 2):
            if node > 100000 or node<0:
                continue
            if visited[node] == visited[temp]+1 or visited[node] == -1:
                visited[node] = visited[temp]+1
                q.append(node)
    print(visited[k])
    print(ans)
solve(n,k)
