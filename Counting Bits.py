class Solution:
    def countBits(self, n: int) -> List[int]:
        counts = [0]*(n+1)
        for i in range(1, n+1):
            if i == 2:
                counts[2] = 1
            elif i & 1:
                counts[i] = counts[i-1]+1
            else:
                counts[i] = counts[i//2]
        return counts
