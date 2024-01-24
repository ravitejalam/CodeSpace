from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dict_nums1 = dict()
        for i in nums1:
            if i in dict_nums1.keys():
                dict_nums1[i] += 1
            else:
                dict_nums1[i] = 1
        ans = []
        for i in nums2:
            if i in dict_nums1.keys():
                if dict_nums1[i] == 1:
                    dict_nums1.pop(i)
                else:
                    dict_nums1[i] -= 1
                ans.append(i)
        return ans


nums1 = [1,2,2,1]
nums2 = [2,2]
print(Solution.intersect(None, nums1,nums2))