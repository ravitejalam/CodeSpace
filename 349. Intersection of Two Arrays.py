from typing import List


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        distinct_nums1 = set(nums1)
        ans = []
        for i in nums2:
            if i in distinct_nums1:
                ans.append(i)
                distinct_nums1.remove(i)
        return ans