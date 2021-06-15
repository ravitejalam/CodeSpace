def base6(decimal):
    scale = 1
    result = 0
    decimal = abs(decimal)

    while decimal > 0:
        digit = decimal % 6
        result += digit * scale
        decimal //= 6
        scale *= 10
    return result
def sumofnumber(number):
    result=0
    while number>0:
        result+=number%10
        number//=10
    return result
n=int(input())
l=list(map(int,input().strip().split(",")))
l=list(map(base6,l))
l=list(map(sumofnumber,l))
c=0
print(l)
for i in range(n-1):
    for j in range(i+1,n):
        if l[i]>l[j]:
            c+=1
print(c,end="")