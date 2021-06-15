p=[1,2,3,4]
q=[1,3,4]
k=2
res=[]
for timing in q:
    capacity=k
    while capacity!=0:
        if len(p)!=0:
            if p[0]>=timing:
                last=p[0]
                del p[0]
                capacity-=1
            else:
                last=0
                del p[0]
        else:
            capacity=0
            last=0
    res.append(last)
print(res)