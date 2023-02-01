import sys
input = sys.stdin.readline
def init(start,end,index):
    if start==end:
        tree[index] = nums[start]
        return tree[index]
    mid = (start+end) // 2
    tree[index] = init(start,mid,index*2) + init(mid+1,end,index*2+1)
    return tree[index]
def lazy_update(start,end,index):
    if lazy[index]:
        tree[index] += (end-start+1)*lazy[index]
        if start!=end:
            lazy[index*2] += lazy[index]
            lazy[index*2+1] +=lazy[index]
        lazy[index]=0
def update(start,end,index,left,right,value):
    lazy_update(start,end,index)
    if right<start or end<left:
        return
    if left<=start and end<=right:
        tree[index] += (end-start+1)*value
        if start!=end:
            lazy[index*2] += value
            lazy[index*2 + 1] +=value
        return
    mid = (start+end) // 2
    update(start,mid,index*2,left,right,value)
    update(mid+1,end,index*2+1,left,right,value)
    tree[index] = tree[index*2] + tree[index*2+1]
def print_query(start,end,index,left,right):
    lazy_update(start,end,index)
    if left>end or right<start:
        return 0
    if left<=start and right>=end:
        return tree[index]
    mid = (start+end) // 2
    return print_query(start,mid,index*2,left,right) + print_query(mid+1,end,index*2+1,left,right)

n = int(input())
nums = [0]
nums = nums+list(map(int,input().split()))
tree = [0]*(4*(n+1))
lazy = [0]*(4*(n+1))
m = int(input())
init(1,n,1)
for _ in range(m):
    query = list(map(int,input().split()))
    if query[0]==1:
        left,right,value = query[1],query[2],query[3]
        update(1,n,1,left,right,value)
    else:
        print(print_query(1,n,1,query[-1],query[-1]))
