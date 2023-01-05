n,m = map(int,input().split())
check=[]
divisor=[]
num = list(range(1,n+1))
def findGroup(chunk,num):
    for index,group in enumerate(chunk): #get index,data
        if num in group: #if found
            return index #return group index
for _ in range(m):
    a,b=map(int,input().split())
    if a>b: # add only back-edges
       check.append((a,b))
for i in range(1,n+1): # get divisors
    if n%i==0:
        divisor.append(i)
for d in divisor:
    flag=True
    chunk = [num[i:i+d] for i in range(0,len(num),d)] #split group within size of divisor
    for city in check:
        if findGroup(chunk,city[0])!=findGroup(chunk,city[1]): #check if a,b are in same group
            flag=False
            break
    if flag:
        print(len(chunk))
        break






