class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        i = 0
        while i < len(nums):
            if nums[nums[i]-1] == nums[i]:
                i += 1
            else:
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        disappeared_numbers = []
        for i, v in enumerate(nums):
            if v != i+1:
                disappeared_numbers.append(i+1)
        return disappeared_numbers
