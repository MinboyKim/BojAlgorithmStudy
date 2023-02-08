import sys
input = sys.stdin.readline
def ccw(x1,x2,x3,y1,y2,y3):
    temp = (x2-x1)*(y3-y1) - (y2 - y1)*(x3-x1)
    if temp>0:
        return 1
    elif temp==0:
        return 0
    else:
        return -1
def checkLine(line1,line2):
    x1,y1,x2,y2 = line1
    x3,y3,x4,y4 = line2
    slope1 = ccw(x1,x2,x3,y1,y2,y3) * ccw(x1,x2,x4,y1,y2,y4)
    slope2 = ccw(x3,x4,x1,y3,y4,y1) * ccw(x3,x4,x2,y3,y4,y2)
    if slope1==0 and slope2==0:
        return (min(x1,x2)<=max(x3,x4) and min(x3,x4)<=max(x1,x2)
                and min(y1,y2) <=max(y3,y4) and min(y3,y4) <=max(y1,y2))
    else:
        return slope1<=0 and slope2<=0
line1 = list(map(int,input().split()))
line2 = list(map(int,input().split()))
print(1 if checkLine(line1,line2) else 0)