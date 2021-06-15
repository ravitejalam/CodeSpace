def goodsegment(badNumbers, l, r):
    badNumbers.append(l-1)
    badNumbers.append(r+1)
    badNumbers = list(set(badNumbers))
    badNumbers.sort()
    n=badNumbers
    il = n.index(l-1)
    ir = n.index(r+1)
    n = n[il:ir + 1]
    length = len(n)
    m = []
    for i in range(length - 1):
        m.append(n[i + 1] - n[i]-1)
    return max(m)


print(goodsegment([5, 4, 2, 15], 1, 10))
