class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastIndex = {}
        parts = []
        head = -1
        last = 0
        for i,v in enumerate(s):
            lastIndex[v] = i
        for i in range(len(s)):
            if i >last:
                parts.append(last-head)
                head = last
            last = max(lastIndex[s[i]],last)
        parts.append(last-head)
        return parts