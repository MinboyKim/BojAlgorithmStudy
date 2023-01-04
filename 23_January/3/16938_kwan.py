from itertools import combinations
n,l,r,x = map(int,input().split())
difficulty = sorted(list(map(int,input().split()))) # sort difficulty by order
ans=0
for i in range(2,n+1):
    for temp in list(combinations(difficulty,i)): # get every possible combinations
        l_sum = sum(temp)
        l_max = max(temp)
        l_min = min(temp)
        if l_max-l_min<x or l_sum<l or l_sum>r: # conditions
            continue
        else:
            ans+=1
print(ans)