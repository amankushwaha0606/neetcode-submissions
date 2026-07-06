class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, nums[0]), right(n, nums[n-1]), ans(n);

        for(int i=1; i<n; i++) {
            left[i] = nums[i]*left[i-1];
            right[n-i-1] = nums[n-i-1]*right[n-i];
        }

        
        for(int i=1; i<n-1; i++) {
            ans[i] = left[i-1]*right[i+1];
        }

        ans[0] = right[1];
        ans[n-1] = left[n-2];
        return ans;

    }
};
