s=input()
s=s.lower()
original=s
l=len(s)
n=int(input())
key=""
flag=0
for i in range(n):
    r,t=input().split()
    t=int(t)%l
    if r=="L":
        s=s[t:]+s[:t]
        key+=s[0]
    else:
        s=s[-t:]+s[:-t]
        key+=s[0]
key=''.join(sorted(key))
kl=len(key)
for j in range(l-n+1):
    if key==''.join(sorted(original[j:j+kl])):
        print("YES",end="")
        flag=1
        break
if flag==0:
    print("NO",end="")