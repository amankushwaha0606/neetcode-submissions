class Solution {
    /**
     * @param {number[]} prices
     * @return {number}
     */
    maxProfit(prices) {
        let mini = prices[0];
        let ans = 0;

        for(let price of prices) {
            mini = Math.min(mini, price);
            ans = Math.max(price-mini, ans);
        }
        return ans;
    }
}
