from sys import stdin
def lowerBound(x,func):
    left,right = 0 , len(func)
    while left<right:
        mid = left+(right-left)//2
        if func[mid][0]<x:
            left = mid+1
        else:
            right = mid
    diff = func[right][1] - func[right - 1][1]
    if diff > 0:
        return 1
    elif diff < 0:
        return -1
    else:
        return diff
n = int(stdin.readline())
func = []
for _ in range(n):
    x,y = map(int,stdin.readline().split())
    func.append((x,y))
q = int(stdin.readline())
for _ in range(q):
    k = float(stdin.readline())
    print(lowerBound(k,func))
