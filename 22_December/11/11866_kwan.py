from collections import deque
n,k = map(int,input().split())
deq = deque(range(1,n+1))
ans = []
while deq:
    deq.rotate(-(k-1))
    ans.append(str(deq.popleft()))
answer = "<" + ", ".join(ans) + ">"
print(answer)
