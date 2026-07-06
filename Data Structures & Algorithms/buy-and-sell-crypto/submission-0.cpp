class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<int> right(n, 0);
        right[n-1] = prices[n-1];

        for(int i=n-2; i>=0; i--) {
            right[i] = max(right[i+1], prices[i]);
        }

        int mini = INT_MAX, ans = 0;

        for(int i=0; i<n; i++) {
            mini = min(mini, prices[i]);
            ans = max(ans, right[i] - mini);
        }

        return ans;
    }
};
