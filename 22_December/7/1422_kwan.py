from functools import cmp_to_key
def compare(x,y):
    if (str(x)+str(y))<(str(y)+str(x)):
        return 1
    else:
        return -1
k,n = map(int,input().split())
num = [int(input()) for _ in range(k)]
sorted_num = sorted(num,key=cmp_to_key(compare))
ans=""
count=n-k
if n>k:
    max_num = max(sorted_num)
    for num in sorted_num:
        ans+=str(num)
        if num==max_num:
            while(count>0):
                ans+=str(num)
                count-=1
else:
    for num in sorted_num:
        ans+=str(num)
print(ans)