class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        stack = []
        pl = len(part)
        for c in s:
            stack.append(c)
            if len(stack) >= len(part) and "".join(stack[-pl:]) == part:
                    stack = stack[:-pl]
        return "".join(stack)
