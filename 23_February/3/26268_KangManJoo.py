import sys
input = sys.stdin.readline
a=list(map(int,input().split()))
gomgom=list(map(int,input().split()))
gomgom.sort()
questionList=[]

def binarySearch1(cur):
    right=len(gomgom)
    left=0
    while left<right:
        mid=(left+right)//2
        if gomgom[mid]>cur:
            right=mid
        else:
            left=mid+1
    return left

def binarySearch1(cur):
    right=len(gomgom)
    left=0
    while left<right:
        mid=(left+right)//2
        if gomgom[mid]>=cur:
            right=mid
        else:
            left=mid+1
    return left

def binarySearch2(cur):
    right=len(gomgom)
    left=0
    while left<right:
        mid=(left+right)//2
        if gomgom[mid]>cur:
            right=mid
        else:
            left=mid+1
    return left

for _ in range(a[1]):
    question=list(map(int,input().split()))
    if(question[0]==1):
        print(len(gomgom)-binarySearch1(question[1]))
    elif question[0]==2:
        print(len(gomgom)-binarySearch2(question[1]))
    elif question[0]==3:
        print(len(gomgom)-binarySearch1(question[1])-(len(gomgom)-binarySearch2(question[2])))
        

