class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 1
        c = 0
        while i < len(nums):
            if nums[i] == nums[i-1]:
                c += 1
            else:
                nums[i-c] = nums[i]
            i += 1
        return len(nums)-c
