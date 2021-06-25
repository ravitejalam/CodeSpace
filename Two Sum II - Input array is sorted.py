class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hashmap = dict()
        for index, val in enumerate(numbers):
            hashmap[val] = index
        for index, val in enumerate(numbers):
            if target - val in hashmap.keys() and hashmap[target - val] is not index:
                return [index+1, hashmap[target - val]+1]
        return []
