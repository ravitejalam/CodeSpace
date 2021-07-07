class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        indexs = [0]*len(matrix)
        ans = -1
        n = len(matrix)
        while k > 0:
            min_index = -1
            minimum = 1000000001
            for i,v in enumerate(indexs):
                if v < n and matrix[i][v] < minimum:
                    minimum = matrix[i][v]
                    min_index = i
            indexs[min_index]+=1
            k-=1
            ans = minimum
        return ans
