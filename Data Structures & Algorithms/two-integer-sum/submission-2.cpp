class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> st;
        for(int i=0; i<nums.size(); i++) {
            int diff = target - nums[i];
            if(st.find(diff) != st.end()) {
                return {st[diff], i};
            }
            st.insert({nums[i], i});
        }
        return {};
    }
};
