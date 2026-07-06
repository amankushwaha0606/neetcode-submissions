class Solution {
    /**
     * @param {number[]} prices
     * @return {number}
     */

    dp = {};
    getProfit(prices, isBuy, index) {
        if(this.dp[`${isBuy}-${index}`]) return this.dp[`${isBuy}-${index}`];
        if(index >= prices.length) return 0;

        let cool = this.getProfit(prices, isBuy, index+1);
        if(isBuy) {
            let buy = this.getProfit(prices, false, index+1) - prices[index];
            this.dp[`${isBuy}-${index}`] = Math.max(cool, buy);
            return this.dp[`${isBuy}-${index}`];
        } else {
            let sell = this.getProfit(prices, true, index+2) + prices[index];
            this.dp[`${isBuy}-${index}`] = Math.max(cool, sell);
            return this.dp[`${isBuy}-${index}`];
        }
    }

    maxProfit(prices) {
        return this.getProfit(prices, true, 0)
    }
}
