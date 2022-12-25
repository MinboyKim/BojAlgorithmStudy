n,k=map(int,input().split())
seq = list(map(int,input().split()))
first_index,last_index=0,k-1
lion = []
count=0
result=int(1e10)
for i in range(len(seq)):
    if seq[i]==1:
        lion.append(i)
if len(lion)<k:
    print(-1)
else:
    while True:
        temp = lion[last_index]-lion[first_index]+1
        result = min(result,temp)
        if last_index==len(lion)-1:
            break
        first_index+=1
        last_index+=1
    print(result)
