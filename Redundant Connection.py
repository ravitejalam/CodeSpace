from typing import List


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        groups = []
        extra_edge = []
        for edge in edges:
            new_group = set(edge)
            index = 0
            while index < len(groups):
                if edge[0] in groups[index] and edge[1] in groups[index]:
                    return edge
                elif edge[0] in groups[index] or edge[1] in groups[index]:
                    new_group.update(groups[index])
                    groups[index], groups[-1] = groups[-1], groups[index]
                    groups.pop()
                    continue
                index += 1
            groups.append(new_group)
        return []

