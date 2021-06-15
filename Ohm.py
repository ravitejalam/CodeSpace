li = []
while True:
    try:
        line = input("")
    except EOFError:
        break
    li.append(line)
for z in range(len(li)):
    string=li[z]
    org=string
    l=list()
    while "=" in string:
        i=string.index("=")
        string=string[i+1:]
        if l==[]:
            l.append(i)
        else:
            l.append(l[-1]+i+1)
    I=list()
    V=list()
    R=list()
    for _ in l:
        if org[_-1]=="I":
            x=_+1
            while org[x] in list('1234567890'):
                I.append(org[x])
                x += 1
        elif org[_-1]=="V":
            x = _ + 1
            while org[x] in list('1234567890'):
                V.append(org[x])
                x += 1
        else:
            x = _ + 1
            while org[x] in list('1234567890'):
                R.append(org[x])
                x += 1
    if R==[]:
        I=float("".join(I))
        V=float("".join(V))
        print("R="+"{:.2f}".format(V/I)+"O")
    elif V==[]:
        I = float("".join(I))
        R = float("".join(R))
        print("V=" + "{:.2f}".format(I*R) + "V")
    else:
        R = float("".join(R))
        V = float("".join(V))
        print("I=" + "{:.2f}".format(V/R) + "A")