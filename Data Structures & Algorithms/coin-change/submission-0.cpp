class Solution {
public:

    int getCoins(vector<int>& coins, int amount, int index, int coin) {

        if(amount < 0 || index == coins.size()) return -1;
        if(amount == 0) return coin;

        int c1 = getCoins(coins, amount-coins[index], index, coin+1);
        int c2 = getCoins(coins, amount, index+1, coin);
        if(c1 == -1) {
            return c2;
        }
        if(c2 == -1) {
            return c1;
        }
        return min(c1, c2);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        return getCoins(coins, amount, 0, 0);
    }
};
