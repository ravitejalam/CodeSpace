t=int(input())
for _ in range(t):
    i,d,z=map(int,input().strip().split())
    if d<z or (d==z and i==0):
        j=0
        c=0
        while j<i:
            i+=d
            j+=z
            c+=1
        print(c,end="")
    else:
        print("-1")