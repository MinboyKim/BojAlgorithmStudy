def binarySearch(size,t):
    l=0
    r=size-1
    while l<r:
        mid = (l+r)//2
        if lis[mid]<t:
            l = mid+1
        else:
            r = mid
    return r
n = int(input())
a = list(map(int,input().split()))
lis = [a[0]]
rec=[]
for num in a:
    if lis[-1]<num:
        lis.append(num)
        rec.append((len(lis)-1,num))
    else:
        new_index = binarySearch(len(lis),num)
        lis[new_index]=num
        rec.append((new_index,num))
print(len(lis))
ans = []
loc = len(lis)-1
for i in range(n-1,-1,-1):
    if rec[i][0] == loc:
        ans.append(rec[i][1])
        loc-=1
    if loc==-1:
        break
print(*reversed(ans))