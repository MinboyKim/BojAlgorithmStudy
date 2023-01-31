import sys
input = sys.stdin.readline
def query(start,end,index,left,right):
    lazy_update(start, end, index)
    if left>end or right<start:
        return 0
    if left<=start and right>=end:
        return tree[index]
    mid = (start+end) // 2
    return query(start,mid,index*2,left,right) + query(mid+1,end,index*2+1,left,right)
def lazy_update(start,end,index):
    if lazy[index]:
        tree[index] = (end-start+1) - tree[index]
        if start!=end:
            lazy[index*2] = not lazy[index*2]
            lazy[index*2 + 1] = not lazy[index*2+1]
        lazy[index] = False
def update(start,end,index,left,right):
    lazy_update(start, end, index)
    if right<start or end<left:
        return
    if left<=start and end<=right:
        tree[index] = (end-start+1) - tree[index]
        if start!= end:
            lazy[index*2] = not lazy[index*2]
            lazy[index*2+1] = not lazy[index*2+1]
        return
    mid = (start + end )//2
    update(start,mid,index*2,left,right)
    update(mid+1,end,index*2+1,left,right)
    tree[index] = tree[index*2] + tree[index*2+1]

n,m = map(int,input().split())
tree = [0]*(4*(n+1))
lazy = [0]*(4*(n+1))
for _ in range(m):
    o,s,t = map(int,input().split())
    if o:
        print(query(1,n,1,s,t))
    else:
        update(1,n,1,s,t)
