import sys
def init(start,end,index):
    if start==end:
        tree[index] = nums[start]
    else:
        mid = (start+end) // 2
        tree[index] = (init(start,mid,index*2)*init(mid+1,end,index*2+1))%divisor
    return tree[index]
def query(start,end,index,left,right):
    if left>end or right<start:
        return 1
    if left<=start and right>=end:
        return tree[index]
    mid = (start+end) // 2
    return (query(start,mid,index*2,left,right) * query(mid+1,end,index*2+1,left,right))%divisor
def update(start,end,index,where,value):
    if where<start or where>end:
        return
    if start==end:
        tree[index] = value
        return
    else:
        mid = (start+end) // 2
        update(start,mid,index*2,where,value)
        update(mid+1,end,index*2+1,where,value)
        tree[index] = (tree[index*2] * tree[index*2+1])% divisor
input = sys.stdin.readline
n,m,k = map(int,input().split())
nums = [0]
tree = [1]*(4*(n+1))
ans=[]
divisor = 1000000007
for _ in range(n):
    nums.append(int(input()))
init(1,n,1)
for _ in range(m+k):
    a,b,c = map(int,input().split())
    if a==1:
        update(1,n,1,b,c)
        nums[b] = c
    else:
        ans.append(int(query(1,n,1,b,c)))
for a in ans:
    print(a)

