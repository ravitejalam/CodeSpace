# https://leetcode.com/problems/next-greater-element-i/

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        r = []
        for i in nums1:
            flag = False
            ans = -1
            for j in nums2:
                if i==j:
                    flag=True
                if flag and j>i:
                    ans = j
                    break
            r.append(ans)
        return r
