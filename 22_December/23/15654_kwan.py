from itertools import permutations
n,m = map(int,input().split())
nums = list(map(int,input().split()))
nums.sort()
ans=permutations(nums,m,)
for l in ans:
    print(*l)
