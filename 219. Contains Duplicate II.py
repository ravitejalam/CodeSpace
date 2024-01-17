from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if not k:
            return False
        visited = set()
        for i in range(len(nums)):
            if not i - k - 1 < 0:
                visited.remove(nums[i - k - 1])
            if nums[i] not in visited:
                visited.add(nums[i])
            else:
                return True
        return False
