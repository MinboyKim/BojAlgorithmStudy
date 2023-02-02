import sys
gomgom=list(map(int,input().split()))
food=list(map(int,input().split()))

i=0
sum=0
for _ in range(6):
    if gomgom[i]>=food[i]:
        gomgom[i]-=food[i]
        sum+=food[i]
        food[i]=0
    else:
        sum+=gomgom[i]
        food[i]-=gomgom[i]
        gomgom[i]=0
        if(i==2):
            food[0]+=food[i]//3
            food[i]=0
        else:
            food[i+1] += food[i] // 3
            food[i] = 0
    i+=1
    if(i>2):
        i=0

print(sum)
