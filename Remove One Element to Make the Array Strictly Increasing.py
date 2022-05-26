class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        prev = 0
        curr = nums[0]
        dips = 0
        for i in nums[1:]:
            if i > curr:
                prev = curr
                curr = i
            else:
                if i > prev:
                    curr = i
                dips+=1
        return dips < 2