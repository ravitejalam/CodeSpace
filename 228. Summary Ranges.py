from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans = []
        if not len(nums):
            return ans
        start = nums[0]
        end = nums[0]
        for i in nums[1:]:
            if i != end + 1:
                if start == end:
                    ans.append(str(start))
                else:
                    ans.append(str(start) + "->" + str(end))
                start = end = i
            else:
                end = i
        if start == end:
            ans.append(str(start))
        else:
            ans.append(str(start) + "->" + str(end))
        return ans
