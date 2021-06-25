class Solution:

    def digitSquareSum(self, n):
        sum = 0
        while n:
            sum += (n % 10)*(n % 10)
            n = n//10
        return sum

    def isHappy(self, n: int) -> bool:
        slow = n
        fast = n
        while True:
            slow = self.digitSquareSum(slow)
            fast = self.digitSquareSum(self.digitSquareSum(fast))
            if slow == fast:
                break
        if slow == 1:
            return True
        return False
