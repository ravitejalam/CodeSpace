class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini = prices[0]
        profit = 0
        for price in prices:
            if price-mini > profit:
                profit = price-mini
        return profit
