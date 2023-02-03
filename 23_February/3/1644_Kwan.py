import math
n = int(input())
prime = [0]*(n+1)
for i in range(2,int(math.sqrt(n))+1):
    if prime[i] == 0:
        for j in range(i+i,len(prime),i):
            prime[j] = 1
prime_num = []
for i in range(2,len(prime)):
    if prime[i]==0:
        prime_num.append(i)
left,right = 0,0
ans=0
while right<len(prime_num):
    val = sum(prime_num[left:right+1])
    if val<n:
        right+=1
    elif val>n:
        left+=1
    else:
        ans+=1
        left+=1
print(ans)