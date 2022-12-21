import sys
n = int(input())
entry = set()
for _ in range(n):
    name,enter=sys.stdin.readline().strip().split()
    if enter=="enter":
        entry.add(name)
    else:
        entry.remove(name)
entry=sorted(entry,reverse=True)
for name in entry:
    print(name)