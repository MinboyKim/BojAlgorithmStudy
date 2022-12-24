import sys
import math
max_num =200000
prime = [0] * max_num
def lowerBound(num):
    for i,n in enumerate(prime_num):
        if n>=num:
            return i
for i in range(2,int(math.sqrt(max_num))+1):
    if prime[i]==0:
        for j in range(i+i, len(prime), i):
            prime[j]=1
prime_num=[]
for i in range(2,len(prime)):
    if prime[i]==0:
        prime_num.append(i)
t = int(input())
for _ in range(t):
    n = int(input())
    x = list(map(int,sys.stdin.readline().split()))
    x.sort()
    min_val = 99999999
    length = len(x)
    index = lowerBound(x[0])
    while True:
        window = prime_num[index:index+length]
        temp = 0
        for i in range(length):
            temp+=abs(x[i]-window[i])
        min_val=min(min_val,temp)
        index+=1
        if window[0]>=x[-1]:
            break
    print(min_val)