class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            nums[i] = nums[i]+nums[i-1];
        }

        nums.insert(nums.begin(), 0);
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                maxSum = max(maxSum, nums[j]-nums[i]);
            }
        }

        return maxSum;
    }
};
