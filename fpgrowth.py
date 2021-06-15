import itertools
data=[[1,2,5],[2,4],[2,3],[1,2,4],[1,3],[2,3],[1,3],[1,2,3,5],[1,2,3]]
counts=[]
temp=list(itertools.chain.from_iterable(data))
m=max(temp)
for i in range(1,m+1):
    counts.append(temp.count(i))
print("counts:",counts)
new_data=[]
for i in data:
    temp=[]
    for j in i:
        temp.append((j,counts[j-1]))
    temp=sorted(temp, key=lambda x: x[1], reverse=True)
    new_data.append(temp)
# print("ordered data and counts:",new_data)
main_data=[]
for i in new_data:
    temp=[]
    for j in i:
        temp.append(j[0])
    main_data.append(temp)
print("ordered data",main_data)
