n=0
def ways(string):
    global n
    if string=="":
        n+=1
    elif string[0]=="0":
        ways(string[1:])
    elif string[0]=="1":
        ways(string[1:])
        if len(string)>1:
            ways(string[2:])
    elif string[0]=="2":
        if len(string)>1:
            if int(string[1])<7:
                ways(string[2:])
        ways(string[1:])
    else:
        ways(string[1:])
string=input()
cipher=""
for i in string:
    cipher+=str(ord(i)-96)
ways(cipher)
print(n)