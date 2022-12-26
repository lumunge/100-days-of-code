class Solution:
    def max_profit(self, prices) -> int:
        l, r = 0, 1 # left, right pointer
        max_profit = 0

        while r < len(prices):
            if prices[l] < prices[r]: # check profitability
                profit = prices[r] - prices[l]
                max_profit = max(max_profit, profit) # update profit
            else: # no profit, shift pointers
                l = r
            r += 1
        return max_profit

if __name__ == "__main__":
    soln = Solution()
    res = soln.max_profit([7,1,5,3,6,4])
    print(res)
