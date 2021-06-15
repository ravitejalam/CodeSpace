class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        opp = {'}':'{',']':'[',')':'('}
        for char in s:
            if char in ('{','(','['):
                stack.append(char)
            elif len(stack) !=0 and stack[-1] == opp[char]:
                stack.pop()
            else:
                return False
        return len(stack) == 0