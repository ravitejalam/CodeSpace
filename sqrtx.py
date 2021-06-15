class Solution:
    def mySqrt(self, x: int) -> int:
        l, h = 0, 46340
        ans = 0
        while l <= h:
            m = l + (h-l)//2
            sq = m*m
            if sq == x:
                return m
            elif sq > x:
                h = m-1
            else:
                l = m+1
                ans = max(ans, m)
        return ans
