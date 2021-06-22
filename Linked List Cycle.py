# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        unique = set()
        tmp = head
        while tmp:
            if tmp in unique:
                return False
            unique.add(tmp)
            tmp = tmp.next
        return True
        