class Solution:
    def isPalindrome(self, s: str) -> bool:
        def isAlphaNum(c):
            return ('0' <= c and c <= '9') or ('A' <= c and c <= 'Z') or ('a' <= c and c <= 'z')

        def isSameChar(a, b):
            return a.lower() == b.lower()

        left = 0
        right = len(s)-1
        while left < right:
            while left < right and not isAlphaNum(s[left]):
                left += 1
            while left < right and not isAlphaNum(s[right]):
                right -=1
            if left < right and not isSameChar(s[left],s[right]):
                return False
            left+=1
            right-=1
        return True
