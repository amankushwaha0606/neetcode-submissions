class Solution {
public:

    int getPath(vector<int>& cost, int index) {
        if(index < 0) return 0;
        if(index == 0) return cost[0];
        if(index == 1) return cost[1];

        return cost[index] + min(getPath(cost, index-1), getPath(cost, index-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return getPath(cost, cost.size());
    }
};
