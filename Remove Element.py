class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        index = 0
        last = len(nums)-1
        while index <= last:
            if nums[index] == val:
                nums[index] = nums[last]
                last -= 1
            else:
                index += 1
        return last+1
