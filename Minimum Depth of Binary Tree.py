# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        leftResult = self.minDepth(root.left)
        rightResult = self.minDepth(root.right)
        return 1 + (min(leftResult,rightResult) or max(leftResult,rightResult))

