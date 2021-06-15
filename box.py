def fun(l):
    start=l[0]
    for i in range(1,len(l)):
        start=start|l[i]
    return start
n=int(input())
l=list(map(int,input().strip().split()))
s=0
t=[]
for i in range(n):
    for j in range(n-i):
        t.append(l[i:(n-j)])
for i in t:
    s+=fun(i)
print(s)
