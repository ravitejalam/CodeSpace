n=int(input())
l=list()
ind=[-1]*(n+1)
while True:
    i=input()
    if i=="-1":
        break
    elif i[0]=="Q":
        if l==[]:
            print("0")
        else:
            c=0
            for _ in l:
                if _%2==0 and _!=0:
                    c+=1
            print(c)
    else:
        I,J=map(int,i[2:].split())
        if l==[]:
            l.append(2)
            ind[I]=0
            ind[J]=0
        else:
            f=0
            if ind[I] != -1:
                if ind[J] == -1:
                    l[ind[I]]+=1
                    ind[J]=ind[I]
                    f=1
                else:
                    if ind[I]!=ind[J]:
                        if I<J:
                            l[ind[I]]+=l[ind[J]]-1
                            b=ind[J]
                            for _ in range(len(ind)):
                                if ind[_]==b:
                                    ind[_]=ind[I]
                            l[ind[J]]=0
                        else:
                            l[ind[J]]+=l[ind[I]]-1
                            b=ind[I]
                            for _ in range(len(ind)):
                                if ind[_]==b:
                                    ind[_]=ind[J]
                            l[ind[I]]=0
                    f=1
            elif ind[J]!= -1:
                l[ind[J]]+=1
                ind[I]=ind[J]
                f=1
            if f==0:
                ind[I]=len(l)
                ind[J]=len(l)
                l.append(2)
