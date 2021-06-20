class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        else:
            l = [1]
            prev = self.getRow(rowIndex-1)
            for i in range(1,rowIndex):
                l.append(prev[i]+prev[i-1])
            l.append(1)
            return l

