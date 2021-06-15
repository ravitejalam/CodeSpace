def qual(i,j,r,c,main):
    co=0
    if i-1>=0 and i-1<r and j>=0 and j<c:
        co+=main[i-1][j]
    if i-1>=0 and i-1<r and j+1>=0 and j+1<c:
        co+=main[i-1][j+1]
    if i>=0 and i<r and j+1>=0 and j+1<c:
        co+=main[i][j+1]
    if i+1>=0 and i+1<r and j+1>=0 and j+1<c:
        co+=main[i+1][j+1]
    if i+1>=0 and i+1<r and j>=0 and j<c:
        co+=main[i+1][j]
    if i+1>=0 and i+1<r and j-1>=0 and j-1<c:
        co+=main[i+1][j-1]
    if i>=0 and i<r and j-1>=0 and j-1<c:
        co+=main[i][j-1]
    if i-1>=0 and i-1<r and j-1>=0 and j-1<c:
        co+=main[i-1][j-1]
    return co

r,c=map(int,input().strip().split())
main=[]
for i in range(r):
    main.append(list(map(int,input().strip().split())))
# print(main)
q=list()
for i in range(r):
    q.append([0]*c)
# print(q)
main[0][0]=0
# print(main)
for i in range(r):
    for j in range(c):
        if main[i][j]==1:
            q[i][j]=qual(i,j,r,c,main)
print(q)
m=0
for i in q:
    if m<max(i):
        m=max(i)
# print(m)
cou=0
for i in range(r):
    for j in range(c):
        if m==q[i][j]:
            cou+=1
# print(cou)
if cou==0:
    print("No suitable girl found",end="")
elif cou==1:
    for i in range(r):
        for j in range(c):
            if q[i][j] == m:
                print(str(i+1) + ":" + str(j+1) + ":" + str(m), end="")
                break
else:
    mini=max(r,c)
    for i in range(r):
        for j in range(c):
            if mini>max(i,j) and q[i][j]==m:
                mini=max(i,j)
    coun=0
    for i in range(r):
        for j in range(c):
            if mini==q[i][j]:
                coun+=1
    if coun==1:
        for i in range(r):
            for j in range(c):
                if q[i][j]==mini:
                    print(str(i+1)+":"+str(j+1)+":"+str(m),end="")
                    break
    else:
        print("Polygamy not allowed", end="")