import sys
def init(start,end,index):
    if start==end:
        tree[index] = nums[start]
        return tree[index]
    mid = (start+end) // 2
    tree[index] = init(start,mid,index*2) + init(mid+1,end,index*2 + 1)
    return tree[index]
def interval_sum(start,end,index,left,right):
    lazy_update(start, end, index)
    if left>end or right<start:
        return 0
    if left<=start and right>=end:
        return tree[index]
    mid = (start+end) // 2
    return interval_sum(start,mid,index*2,left,right) + interval_sum(mid+1,end,index*2+1,left,right)
def lazy_update(start,end,index):
    if lazy[index]:
        tree[index] +=(end-start+1) * lazy[index]
        if start!=end:
            lazy[index*2] +=lazy[index]
            lazy[index*2 + 1] +=lazy[index]
        lazy[index] = 0
def update(start,end,index,left,right,value):
    lazy_update(start, end, index)
    if right<start or end<left:
        return
    if left<=start and end<=right:
        tree[index] += (end-start+1) * value
        if start!= end:
            lazy[index*2] +=value
            lazy[index*2+1] +=value
        return
    mid = (start + end )//2
    update(start,mid,index*2,left,right,value)
    update(mid+1,end,index*2+1,left,right,value)
    tree[index] = tree[index*2] + tree[index*2+1]

n,m,k = map(int,input().split())
nums = []
tree = [0]*(4040404)
lazy = [0]*(4040404)
for _ in range(n):
    nums.append(int(sys.stdin.readline()))
init(0,n-1,1)
for _ in range(m+k):
    query = list(map(int,sys.stdin.readline().split()))
    if query[0]==1:
        update(0,n-1,1,query[1]-1,query[2]-1,query[-1])
    elif query[0]==2:
        print(interval_sum(0,n-1,1,query[1]-1,query[2]-1))
