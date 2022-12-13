import sys
from collections import OrderedDict
n,m = map(int,sys.stdin.readline().strip().split())
dic = OrderedDict()
for i in range(1,n+1):
    dic[i] = sys.stdin.readline().strip()
reversed_dic = dict(map(reversed,dic.items()))
for j in range(m):
    t = sys.stdin.readline().strip()
    if t.isdigit():
        print(dic[int(t)])
    else:
        print(reversed_dic[t])