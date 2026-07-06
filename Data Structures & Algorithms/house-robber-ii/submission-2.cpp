class Solution {
public:
    int robCollect(vector<int>& nums, int index, vector<int>& v) {
        if(v[index]) return v[index];
        if(index == 0) return nums[0];
        if(index == 1) return max(nums[0], nums[1]);

        v[index] = max(robCollect(nums, index-1, v), nums[index] + robCollect(nums, index-2, v));
        return v[index];
    }

    int robLinear(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;

        for(int i=start; i<=end; i++) {
            int pick = nums[i] + prev1;
            int skip = prev2;
            int maxi = max(pick, skip);
            prev1 = prev2;
            prev2 = maxi;
        }

        return prev2;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        int c1 = robLinear(nums, 0, nums.size()-2);
        int c2 = robLinear(nums, 1, nums.size()-1);
        return max(c1, c2);
    }
};
