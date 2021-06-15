def insert(l,parent,name):
    # l - list of nodes
    # parent - name of parent node
    # name - name of the new node
    lenl=len(l)
    flag=False
    for i in range(lenl):
        if l[i][0] == parent:
            l[i].append(lenl)
            flag=True
            break
    if flag:
        l.append([name])
    else:
        print("No node with parent name")
    return l

def delete(l,name):
    # l - list of nodes
    # name - name of the node
    flag=False
    for i in range(len(l)):
        if l[i][0] == name:
            ind=i
            while len(l[i])!=1:
                l=delete(l,l[l[i][-1]][0])
            for i in range(len(l)):
                for j in range(1, len(l[i])):
                    if l[i][j] == ind:
                        del l[i][j]
                    elif l[i][j] > ind:
                        l[i][j] -= 1
            l.remove([name])
            break
    return l

l=[]
name=input("root node name: ")
l.append([name])
while True:
    inp=input("1:insert\t2:delete : ")
    if inp=="1":
        name=input("node name: ")
        parent=input("parent name: ")
        l=insert(l,parent,name)
    elif inp=="2":
        name=input("node name: ")
        l=delete(l,name)
        print("deleted")
    else:
        print("invalid INPUT")
    print(l)