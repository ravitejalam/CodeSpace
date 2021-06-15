import itertools

def Grade(i,grade):
    if grade=="A":
        if 24<=i<=50:
            return True
        return False
    elif grade=="B":
        if 15<=i<=25:
            return True
        return False
    elif grade=="C":
        if 3<=i<=18:
            return True
        return False
    elif grade=="D":
        if 45<=i<=70:
            return True
        return False

def grademem(grade):
    if grade=="A":
        return A
    elif grade=="B":
        return B
    elif grade=="C":
        return C
    elif grade=="D":
        return D

def isChild(x):
    if 3<=x and x<=20:
        return True
    return False

def isYoung(x):
    if 21<=x and x<=40:
        return True
    return False

def isAdult(x):
    if 41<=x and x<=49:
        return True
    return False

def isOld(x):
    if 50<=x and x<=70:
        return True
    return False

def mrngcost(grade):
    c=0
    temp=grademem(grade)
    for i in temp:
        if (not isChild(i)):
            c+=1
    return c

def aftrcost(grade):
    c=0
    temp=grademem(grade)
    for i in temp:
        if (not isYoung(i)):
            c+=1
    return c

def evencost(grade):
    c=0
    temp=grademem(grade)
    for i in temp:
        if (not isAdult(i)):
            c+=1
    return c

def nitcost(grade):
    c=0
    temp=grademem(grade)
    for i in temp:
        if (not isOld(i)):
            c+=1
    return c

def score(i):
    l=list(i)
    return costs[l[0]][0]+costs[l[1]][1]+costs[l[2]][2]+costs[l[3]][3]

movie_names=input().strip().split()
movie_grades=input().strip().split()
tickets_cost=list(map(int,input().strip().split()))
n=int(input())
ages=list(map(int,input().strip().split()))

# movie_names = "Movie1 Movie2 Movie3 Movie4".strip().split()
# movie_grades="A B D C".strip().split()
# tickets_cost=list(map(int,"10 20 15 5".strip().split()))
# n=11
# ages=list(map(int,"23 43 6 7 1 0 45 4 6 7 24".strip().split()))

posi=list(itertools.permutations([0,1,2,3],4))

A=[x for x in ages if Grade(x,"A")]
B=[x for x in ages if Grade(x,"B")]
C=[x for x in ages if Grade(x,"C")]
D=[x for x in ages if Grade(x,"D")]
# print("Ages",ages)
# print("A",A,"\nB",B,"\nC",C,"\nD",D)

costs=[]
for _ in range(4):
    costs.append([tickets_cost[_]*mrngcost(movie_grades[_]),tickets_cost[_]*aftrcost(movie_grades[_]),tickets_cost[_]*evencost(movie_grades[_]),tickets_cost[_]*nitcost(movie_grades[_])])
# print("MOVIE COSTS:",costs)

scores=list()
for i in posi:
    scores.append(score(i))
m=max(scores)
# print("max comb:",scores.count(m))

ind=list()
for z in range(len(scores)):
    if scores[z]==m:
        ind.append(z)
# print("INDEX:",ind)

final=list()
for z in ind:
    final.append(list(posi[z]))
# print("Final:",final)

for z in final:
    print(movie_names[z[0]],movie_names[z[1]],movie_names[z[2]],movie_names[z[3]])

print("Maximum Profit:",m,end="")