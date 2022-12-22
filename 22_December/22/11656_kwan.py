word = list(input().strip())
ans=[]
for i in range(len(word)):
    ans.append(word[i:])
ans.sort()
for w in ans:
    print("".join(w))