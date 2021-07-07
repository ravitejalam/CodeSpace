class Solution:
    def getMaxPalindrome(self, s: str, left: int, rigth: int) -> int:
        pal = ""
        n = len(s)
        while left >= 0 and rigth < n:
            if s[left] == s[rigth]:
                pal = s[left:rigth+1]
                left -= 1
                rigth += 1
            else:
                break
        return pal

    def longestPalindrome(self, s: str) -> str:
        ans = ""
        n = len(s)
        if n < 2:
            return s
        for i in range(n):
            tmp = self.getMaxPalindrome(s, i, i)
            if len(ans) < len(tmp):
                ans = tmp
            tmp = self.getMaxPalindrome(s, i, i+1)
            if len(ans) < len(tmp):
                ans = tmp
        return ans
