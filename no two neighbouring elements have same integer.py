def minCost(neighbours):
    if len(neighbours) == 0:
        return 0
    cost1 = 0
    cost2 = 0
    prev1 = False
    prev2 = True
    for n in neighbours:
        if prev1 ^ n:
            prev1 = n
        else:
            prev1 = not prev1
            cost1 += 1
        if prev2 ^ n:
            prev2 = n
        else:
            prev2 = not prev2
            cost2 += 1
    return min(cost1, cost2)


l = [1, 0, 1, 0, 1, 0]
print(minCost(l))
