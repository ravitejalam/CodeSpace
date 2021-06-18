# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        dq = deque([(root.left, root.right),])
        while dq:
            l,r = dq.popleft()
            if l is None and r is None:
                continue
            if l is None or r is None:
                return False
            if l.val == r.val:
                dq.append((l.left,r.right))
                dq.append((l.right,r.left))
            else:
                return False
        return True
