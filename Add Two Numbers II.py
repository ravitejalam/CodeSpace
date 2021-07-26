class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def rev(l: ListNode) -> ListNode:
            r = None
            while l:
                tmp = l
                l = l.next
                tmp.next = r
                r = tmp
            return r
        r1 = rev(l1)
        r2 = rev(l2)
        ans = None
        over = 0
        while r1 or r2:
            sum = over
            if r1:
                sum+=r1.val
                r1 = r1.next
            if r2:
                sum+=r2.val
                r2 = r2.next
            ans = ListNode(sum%10, ans)
            over = sum//10
        if over:
            ans = ListNode(over, ans)
        return ans   