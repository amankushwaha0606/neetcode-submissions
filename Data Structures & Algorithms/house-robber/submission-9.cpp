class Solution {
public:

    int robCollect(vector<int>& nums, int index, vector<int>& v) {
        if (index < 0) return 0;
        if (v[index]) return v[index];
        if (index == 0) return v[0] = nums[0];
        if (index == 1) return v[1] = max(nums[0], nums[1]);

        v[index] = max(robCollect(nums, index-1, v), nums[index] + robCollect(nums, index-2, v));
        return v[index];
    }

    int rob(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        return robCollect(nums, nums.size()-1, v);
    }
};
