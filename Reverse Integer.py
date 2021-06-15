class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        rev = 0
        sign = [1,-1][x<0]
        if INT_MIN == x:
            return 0
        x = abs(x)
        while x:
            digit = x % 10
            if rev > INT_MAX//10:
                return 0
            if sign == 1 and rev == INT_MAX//10 and digit > 7:
                return 0
            if sign == -1 and rev == INT_MIN//10 and digit > 8:
                return 0
            rev = rev*10 + digit
            x//=10
        return sign * rev

print(Solution.reverse(0,-123))
