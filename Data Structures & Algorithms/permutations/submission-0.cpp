class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int i) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int idx=i; idx<nums.size(); idx++) {
            swap(nums[i], nums[idx]);
            backtrack(nums, i+1);
            swap(nums[i], nums[idx]);
        }
    }
};
