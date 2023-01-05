n=int(input())
a = list(map(int,input().split()))
a = sorted(a) #sort values
ans = sorted([int(d/(i+1)) for i,d in enumerate(a)]) # index,data enumerate
# divide hour with days to get minimum value
print(min(ans[0],a[0])) #answer can't be greater than min value of Ai