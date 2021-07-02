class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        minimun = max(weights)
        maximum = sum(weights)
        ans = maximum
        while minimun <= maximum:
            mid = minimun + (maximum-minimun)//2
            curr_days = 0
            curr_weight = 0
            for weight in weights:
                if curr_weight+weight <= mid:
                    curr_weight += weight
                else:
                    curr_days += 1
                    curr_weight = weight
            if curr_weight:
                curr_days += 1
            if curr_days <= days:
                ans = min(ans, mid)
                maximum = mid-1
            else:
                minimun = mid+1
        return ans

