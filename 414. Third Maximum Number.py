from typing import List


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        distinct_nums = list(set(nums))
        nth_max = 3
        if len(distinct_nums) < nth_max:
            return max(distinct_nums)
        for _ in range(nth_max):
            for i in range(1, len(distinct_nums)):
                if distinct_nums[i] < distinct_nums[i - 1]:
                    distinct_nums[i], distinct_nums[i - 1] = distinct_nums[i - 1], distinct_nums[i]
        return distinct_nums[-nth_max]
