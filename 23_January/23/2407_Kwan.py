import math
n,m = map(int,input().split())
print(int(math.factorial(n)//((math.factorial(n-m))*(math.factorial(m)))))
