n,ql=map(int,input().strip().split())
l=list(map(int,input().strip().split()))
q=list()
c=[0]*ql
for _ in range(ql):
    q.append(list(map(int,input().split())))
for i in l:
    for j in range(ql):
        if q[j][0]<=i<=q[j][1]:
            c[j]+=1
print("\n".join(list(map(str,c))))