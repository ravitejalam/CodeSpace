l=list(map(int,input().strip().split(",")))
h1=-1
h2=-1
m1=-1
m2=-1
s1=-1
s2=-1
if all(elem in l for elem in [2,4,0,0,0,0]):
    print("24:00:00",end="")
else:
    #Hours
    if (2 in l) and h2==-1:
        l.remove(2)
        h1=2
        if 3 in l:
            h2=3
            l.remove(3)
        elif 2 in l:
            h2=2
            l.remove(2)
        elif 1 in l:
            h2=1
            l.remove(1)
        elif 0 in l:
            h2=0
            l.remove(0)
        else:
            l.append(2)
    if (1 in l) and h2==-1:
        l.remove(1)
        h1=1
        h2=max(l)
        l.remove(h2)
    if (0 in l) and h2==-1:
        l.remove(0)
        h1=0
        h2=max(l)
        l.remove(h2)
    #Minutes
    if 5 in l:
        l.remove(5)
        m1=5
        m2=max(l)
        l.remove(m2)
    elif 4 in l:
        l.remove(4)
        m1 = 4
        m2 = max(l)
        l.remove(m2)
    elif 3 in l:
        l.remove(3)
        m1 = 3
        m2 = max(l)
        l.remove(m2)
    elif 2 in l:
        l.remove(2)
        m1 = 2
        m2 = max(l)
        l.remove(m2)
    elif 1 in l:
        l.remove(1)
        m1 = 1
        m2 = max(l)
        l.remove(m2)
    elif 0 in l:
        l.remove(0)
        m1=0
        m2=max(l)
        l.remove(m2)
    #Seconds
    if 5 in l:
        l.remove(5)
        s1=5
        s2=max(l)
        l.remove(s2)
    elif 4 in l:
        l.remove(4)
        s1 = 4
        s2 = max(l)
        l.remove(s2)
    elif 3 in l:
        l.remove(3)
        s1 = 3
        s2 = max(l)
        l.remove(s2)
    elif 2 in l:
        l.remove(2)
        s1 = 2
        s2 = max(l)
        l.remove(s2)
    elif 1 in l:
        l.remove(1)
        s1 = 1
        s2 = max(l)
        l.remove(s2)
    elif 0 in l:
        l.remove(0)
        s1 = 0
        s2 = max(l)
        l.remove(s2)
    if h1!=-1 and h2!=-1 and m1!=-1 and m2!=-1 and s1!=-1 and s2!=-1:
        print("{0}{1}:{2}{3}:{4}{5}".format(h1,h2,m1,m2,s1,s2),end="")
        # print(h1,h2,":",m1,m2,":",s1,s2,end="")
    else:
        print("Impossible",end="")
