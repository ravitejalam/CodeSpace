n=int(input())
l=list()
m=0
for i in range(n):
    l.append(input().strip())
    if m<len(l[-1]):
        m=len(l[-1])
if n==1:
    print(l[0])
else:
    for i in range(m):
        c=1
        for _ in range(1,n):
            if l[_][i]==l[0][i]:
                c+=1
            else:
                break
        if c==n:
            ind=i
        else:
            i-=1
            break
    print(l[0][:i+1])