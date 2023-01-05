n,m=map(int,input().split())
lines = list(map(int,input().split()))
x,y=map(int,input().split())
counts=[]
lp, rp = 0,0
diff = 0
if n==1:
    print(m-y)
else:
    while lp<=rp<len(lines):
        left_val = lines[lp]
        right_val = lines[rp]
        diff = right_val-left_val+1
        if diff>=x:
            counts.append(rp-lp+1)
            lp+=1
        else:
            rp+=1
    if y==0:
        print(m-y)
    else:
        print(m-min(counts)) if min(counts)>y else print(m-y)
