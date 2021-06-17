class Solution:
    flag = True
    dp = []

    def climbStairs(self, n: int) -> int:
        if self.flag:
            self.dp = [1, 1]
            for step in range(2, 46):
                self.dp.append(self.dp[-1]+self.dp[-2])
            self.flag = False
        return self.dp[n]

