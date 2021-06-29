class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        i = 0
        zeros = 0
        while i < len(nums)-zeros:
            if nums[i] == 0:
                zeros += 1
                for j in range(i+1, len(nums)):
                    nums[j-1] = nums[j]
                nums[-1] = 0
            else:
                i += 1
        return nums
