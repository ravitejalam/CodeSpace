class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        major = -1
        count = 0
        for val in nums:
            if count == 0:
                major = val
                count += 1
            elif major == val:
                count += 1
            else:
                count -= 1
        return major
