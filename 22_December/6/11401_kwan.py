def fastPower(num,pow):
    if pow==0:
        return 1
    elif pow == 1:
        return num
    if pow%2==0:
        temp = fastPower(num,pow/2)
        return (temp*temp) % MOD
    else:
        temp = fastPower(num,pow-1)
        return (temp*num) % MOD
n,k = map(int,input().split())
MOD = 1000000007
factorial = [1 for _ in range(n+1)]
for i in range(2,n+1):
    factorial[i] = factorial[i-1] * i % MOD
ans = ((factorial[n]%MOD)*fastPower((factorial[n-k]*factorial[k])%MOD,MOD-2)%MOD)%MOD
print(ans)