import sys
s = set()
all_set = set([i for i in range(1,21)])
m = int(sys.stdin.readline())
for _ in range(m):
    str = sys.stdin.readline().strip()
    if str=="all":
        s.clear()
        s=all_set
    elif str=="empty":
        s.clear()
    else:
        com,num = str.split()
        if com=="add":
            s.add(int(num))
        elif com=="remove":
            if int(num) in s:
                s.remove(int(num))
        elif com=="check":
            if int(num) in s:
                print(1)
            else:
                print(0)
        elif com=="toggle":
            if int(num) in s:
                s.remove(int(num))
            else:
                s.add(int(num))

