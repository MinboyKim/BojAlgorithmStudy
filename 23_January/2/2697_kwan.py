t = int(input())
for _ in range(t):
    n =list(map(int,list(input())))
    index = len(n)
    idx=0
    for i in range(index-1,0,-1):
        if n[i]>n[i-1]:
            if i==index-1:
                idx=index-2
            else:
                idx=i-1
            break
    front = n[:idx]
    back = n[idx:]
    if not front or not back:
        print("BIGGEST")
    else:
        back.sort()
        for i in range(len(back)):
            if back[i]>n[idx]:
                front.append(back.pop(i))
                front.extend(back)
                break
        print(''.join(map(str,front)))
