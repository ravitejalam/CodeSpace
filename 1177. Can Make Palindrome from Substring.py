from typing import List


class Solution:
    @staticmethod
    def helper(counts, replaces):
        misses = 0
        for i in counts:
            if i & 1:
                misses += 1
        return misses // 2 <= replaces

    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        dp = [[0]*26 for i in range(len(s)+1)]
        ans = []
        for i in range(len(s)):
            dp[i + 1] = dp[i].copy()
            dp[i + 1][ord(s[i]) - ord('a')] += 1
        for q in queries:
            counts = []
            for i in range(26):
                counts.append(dp[q[1] + 1][i] - dp[q[0] + 1][i])
            ans.append(self.helper(counts, q[2]))
        return ans


if __name__ == '__main__':
    Solution.canMakePaliQueries(Solution, "hunu",
                                [[0, 3, 1], [1, 1, 1], [2, 3, 0], [3, 3, 1], [0, 3, 2], [1, 3, 3], [2, 3, 1],
                                 [3, 3, 1],
                                 [0, 3, 0], [1, 1, 1], [2, 3, 0], [3, 3, 1], [1, 1, 1]])
