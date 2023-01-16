import sys
def init(start,end,index):
    if start==end:
        tree[index] = nums[start]
        return tree[index]
    mid = (start+end) // 2
    tree[index] = init(start,mid,index*2)+init(mid+1,end,index*2+1)
    return tree[index]
def interval_sum(start,end,index,left,right):
    if left>end or right<start:
        return 0
    if left<=start and right>=end:
        return tree[index]
    mid = (start+end) // 2
    return interval_sum(start,mid,index*2,left,right) + interval_sum(mid+1,end,index*2+1,left,right)
def update(start,end,index,where,value):
    if where<start or where>end:
        return
    tree[index]+=value
    if start == end:
        return
    mid = (start+end) // 2
    update(start,mid,index*2,where,value)
    update(mid+1,end,index*2+1,where,value)
n,m,k = map(int,sys.stdin.readline().split())
nums = []
tree = [0]*(4*n)
for _ in range(n):
    nums.append(int(sys.stdin.readline()))
init(0,n-1,1)
ans =[]
for _ in range(m+k):
    a,b,c= map(int,sys.stdin.readline().split())
    if a==1:
        diff = c-nums[b-1]
        nums[b-1]=c
        update(0,n-1,1,b-1,diff)
    elif a==2:
        ans.append(interval_sum(0,n-1,1,b-1,c-1))
for i in range(k):
    print(ans[i])