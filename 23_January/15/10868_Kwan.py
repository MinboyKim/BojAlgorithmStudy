import sys
n,m = map(int,input().split())
nums = []
tree = [1000000001]*(n*4)
def init(start,end,index):
    if start==end:
        tree[index] = nums[start]
        return tree[index]
    mid = (start+end) // 2
    tree[index] = min(init(start,mid,index*2),init(mid+1,end,index*2+1))
    return tree[index]
def interval_sum(start,end,index,left,right):
    if left>end or right<start:
        return 1000000001
    if left<=start and right>=end:
        return tree[index]
    mid = (start+end) // 2
    return min(interval_sum(start,mid,index*2,left,right),interval_sum(mid+1,end,index*2+1,left,right))
for _ in range(n):
    nums.append(int(sys.stdin.readline()))
init(0,n-1,1)
for _ in range(m):
    a,b= map(int,sys.stdin.readline().split())
    print(interval_sum(0,n-1,1,a-1,b-1))