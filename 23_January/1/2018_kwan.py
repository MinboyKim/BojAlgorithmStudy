n=int(input())
count=0
lp,rp=1,1
while rp<n+1:
    sums = sum([i for i in range(lp,rp)])
    if sums>n:
        lp+=1
    elif sums<n:
        rp+=1
    else:
        count+=1
        rp+=1
print(count+1)