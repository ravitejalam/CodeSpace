# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverse(self, head: ListNode) -> ListNode:
        reversed_head = None
        while head:
            tmp = head
            head = head.next
            tmp.next = reversed_head
            reversed_head = tmp
        return reversed_head

    def isPalindrome(self, head: ListNode) -> bool:
        slow = head
        fast = head
        while fast.next:
            slow = slow.next
            fast = fast.next
            fast = fast.next
        reversed_second_half_head = self.reverse(slow)
        while reversed_second_half_head:
            if head.val != reversed_second_half_head.val:
                return False
            head = head.next
            reversed_second_half_head = reversed_second_half_head.next
        return True
