class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        result = ""
        for i in range(n):
            ans = 1
            left = i - 1
            right = i + 1
            while left >= 0 and right < n and s[left] == s[right]:
                ans += 2
                left -= 1
                right += 1
            if len(result) < ans:
                result = s[left + 1:right]
            ans = 0
            left = i
            right = i + 1
            while left >= 0 and right < n and s[left] == s[right]:
                ans += 2
                left -= 1
                right += 1
            if len(result) < ans:
                result = s[left + 1:right]
        return result
