# Definition for singly-linked list.
from typing import Text


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        reverse = None
        while head:
            tmp = head
            head = head.next
            tmp.next = reverse
            reverse = tmp
        return reverse