n,m=map(int,input().split())
ans = list(map(int,input().split()))
parent = [i for i in range(0,n+1)]
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]
def union(x,y):
    x_root = find(x)
    y_root = find(y)
    if x_root in ans and y_root in ans:
        return
    if x_root in ans:
        parent[y_root]=x_root
    elif y_root in ans:
        parent[x_root]=y_root
    else:
        if x_root<y_root:
            parent[y_root] = x_root
        else:
            parent[x_root] = y_root
parties = []
cnt=0
if ans[0]!=0:
    ans = set(ans[1:])
    for _ in range(m):
        temp=list(map(int,input().split()))
        party = temp[1:]
        for i in range(0,len(party)-1):
            for j in range(i+1,len(party)):
                union(party[i],party[j])
        parties.append(party)
    for party in parties:
        flag = True
        for person in party:
            if find(person) in ans:
                flag = False
                break
        if flag:
            cnt+=1
            flag = False
    print(cnt)
else:
    print(m)
