n,m=map(int,input().split())
t = input()
llist = [set([i])for i in range(0,n+1)]
liar = [False for _ in range(0,n+1)]
parties = []
cnt=0
if t:
    ans = set(list(map(int,t.split()))[1:])
    for _ in range(m):
        temp=list(map(int,input().split()))
        party = set(temp[1:])
        parties.append(party)
        if not ans.isdisjoint(party):
            ans = ans.union(party)
        for person in party:
            llist[person] = llist[person].union(party)
    for party in parties:
        if not ans.isdisjoint(party):
            ans = ans.union(party)
    for i, num in enumerate(llist):
        if not num.isdisjoint(ans):
            liar[i] = True
    for party in parties:
        flag = True
        for num in party:
            if liar[num]:
                flag=False
                break
        if flag:
            cnt+=1
            flag = False
    print(cnt)
else:
    print(m)
