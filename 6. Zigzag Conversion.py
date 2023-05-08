class Solution:
    def convert(self, s: str, numRows: int) -> str:
        rows = []
        for _ in range(numRows):
            rows.append([])
        curr = 0
        flag = True
        if numRows == 1:
            return s
        for c in s:
            if curr == -1:
                flag = True
                curr += 2
            if curr == numRows:
                flag = False
                curr -= 2
            rows[curr].append(c)
            if flag:
                curr += 1
            else:
                curr -= 1
        ans = ""
        for x in rows:
            ans += "".join(x)
        return ans