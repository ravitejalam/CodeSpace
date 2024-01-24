from typing import List


class NumArray:
    nums_left_sum = None

    def __init__(self, nums: List[int]):
        self.nums_left_sum = [0]
        for i in nums:
            self.nums_left_sum.append(self.nums_left_sum[-1] + i)

    def sumRange(self, left: int, right: int) -> int:
        return self.nums_left_sum[right + 1] - self.nums_left_sum[left]

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
