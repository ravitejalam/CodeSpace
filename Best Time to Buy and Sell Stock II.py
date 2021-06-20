class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        N = len(prices)-1
        profit = 0
        while i < N: 
            while i < N and prices[i] >= prices[i+1]:
                i+=1
            buyingPrice = prices[i]
            while i < N and prices[i+1] > prices[i]:
                i+=1
            sellingPrice = prices[i]
            profit += sellingPrice-buyingPrice
        return profit