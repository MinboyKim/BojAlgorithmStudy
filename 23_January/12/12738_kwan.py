def lower_bound(left,right,num):
    while left<right:
        mid = (left+right) // 2
        if length[mid] < num:
            left = mid+1
        else:
            right = mid
    return right
n = int(input())
A = list(map(int,input().split()))
length = [A[0]]
ans=0
for i,num in enumerate(A):
    if num>length[-1]:
        length.append(num)
        ans+=1
    else:
        index=lower_bound(0,len(length)-1,num)
        length[index]=num
print(len(length))