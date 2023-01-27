import sys
from collections import defaultdict
def binarySearch(seq,size,t):
    l = 0
    r = size-1
    while l<r:
        mid = (l+r)//2
        if seq[mid]<t:
            l = mid+1
        else:
            r = mid
    return r
def get_lis_len(seq):
    length = [-99999999]
    ans = 0
    for i,num in enumerate(seq):
        if num>length[-1]:
            length.append(num)
            ans+=1
        else:
            index = binarySearch(length,len(length),num)
            length[index]=num
    return ans
n = int(input())
a = defaultdict(int)
nums = list(map(int,sys.stdin.readline().split()))
for index,value in enumerate(nums):
    a[value]=index
b = list(map(int,sys.stdin.readline().split()))
query = []
for num in b:
    query.append(a[num])
print(get_lis_len(query))