# Definition for a binary tree node.
from statistics import mean
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def merge(dict1, dict2):
    for key, value in dict2.items():
        if key in dict1:
            dict1[key].extend(value)
        else:
            dict1[key] = value
    return dict1


def bfs(root, level) -> dict:
    if root is None:
        return dict()
    values = {level: [root.val]}
    values = merge(bfs(root.right, level + 1), values)
    values = merge(bfs(root.left, level + 1), values)
    return values

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        values_in_levels = bfs(root, 0)
        ans = []
        for i in range(0, len(values_in_levels.keys())):
            ans.append(mean(values_in_levels.get(i)))
        return ans
