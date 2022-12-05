n,k = map(int,input().split())
coins=[int(input()) for _ in range(n)]
sum_dict = {}
for i in range(k+1):
    sum_dict[i]=0
unit_coin = min(coins)
for coin in sorted(coins):
    if coin==unit_coin:
        for i in range(coin,k+1):
            if i%coin == 0:
                sum_dict[i]+=1
    else:
        for i in range(coin,k+1):
            if i==coin:
                sum_dict[i]+=1
            else:
                sum_dict[i]+=sum_dict[i-coin]
print(sum_dict[k])