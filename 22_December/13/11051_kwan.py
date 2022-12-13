def fastPower(num,pow):
    if pow==0:
        return 1
    elif pow==1:
        return num
    if pow%2==0:
        temp = fastPower(num,pow/2)
        return (temp*temp)%MOD
    else:
        temp = fastPower(num,pow-1)
        return (temp*num)%MOD
n,k = map(int,input().split())
fact = [1 for _ in range(n+1)]
MOD = 10007
for i in range(2,n+1):
    fact[i] = fact[i-1]*i
ans = ((fact[n]%MOD)*fastPower((fact[n-k]*fact[k])%MOD,MOD-2)%MOD)%MOD
print(int(ans))