class Solution:
    def myAtoi(self, s: str) -> int:
        def getDigit(c):
            return ord(c) - ord('0')

        def getSign(char):
            if char == '-':
                return -1
            elif char == '+':
                return 1
            return 0

        def isDigit(char):
            if len(char) != 1:
                return
            return ord('0') <= ord(char) <= ord('9')

        s = s.lstrip(' ')
        ans = 0
        if len(s) == 0:
            return ans
        flag = getSign(s[0])
        if flag != 0:
            s = s[1:]
        else:
            flag = 1
        for c in s:
            if isDigit(c):
                ans = ans * 10 + getDigit(c)
            else:
                break
        ans = ans * flag
        low = -2147483648
        high = 2147483647
        if ans < low:
            return low
        elif ans > high:
            return high
        else:
            return ans