import sys
sys.setrecursionlimit(10**6)
def dfs(start):
    global count
    visited[start]=True
    cycle.append(start)
    if not visited[graph[start]]: # recursively search if not visited
        dfs(graph[start])
    else:
        if graph[start] in cycle: #if visited, search for cycle stack
            count-=len(cycle[cycle.index(graph[start]):]) #slice with index
            return # if not sliced, length of stack will be entire graph, not only cycle.
t = int(input())
for i in range(t):
    n = int(input())
    graph=[0]
    graph.extend(list(map(int,input().split())))
    visited = [False]*(n+1)
    count=n
    for i in range(1,n+1):
        if not visited[i]:
            cycle=[]
            dfs(i)
    print(count)
