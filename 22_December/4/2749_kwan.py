n = int(input())
d = {}
m = int(1e+6)
p = int(15*(m/10))
d[0] = 0
d[1] = 1
d[2] = 1
for i in range(3,p):
    d[i] = (d[i-1]%m+d[i-2]%m)%m
print(d[n%p])

