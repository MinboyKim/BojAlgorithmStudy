import math
import sys
max_num = int(2e+06)+1
prime = [0]*max_num
prime[1]=1
for i in range(2,int(math.sqrt(max_num))+1):
    if prime[i]==0:
        for j in range(i+i,len(prime),i):
            prime[j]=1
prime_num = []
for i in range(2,len(prime)):
    if prime[i]==0:
        prime_num.append(i)
def isPrime(num):
    for i in range(1,len(prime_num)):
        if prime_num[i]**2>num:
            break
        if num%prime_num[i]==0: return 0
    return 1
t = int(sys.stdin.readline())
for _ in range(t):
    a,b = map(int,sys.stdin.readline().split())
    num=a+b
    if num%2==0:
        if num==2:
            print("NO")
        else:
            print("YES")
    else:
        if num<=3:
            print("NO")
        else:
            num -= 2
            if isPrime(num):
                print("YES")
            else:
                print("NO")
