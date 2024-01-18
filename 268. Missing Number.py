from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        xor = nums[0] ^ 0 ^ 1
        _ = 2
        for i in nums[1:]:
            xor ^= i ^ _
            _ += 1
        return xor
