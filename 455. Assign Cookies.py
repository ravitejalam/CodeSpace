from typing import List


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        g_index = 0
        s_index = 0
        children_contented = 0
        while s_index < len(s) and g_index < len(g):
            if s[s_index] >= g[g_index]:
                children_contented += 1
                g_index += 1
            s_index += 1
        return children_contented
