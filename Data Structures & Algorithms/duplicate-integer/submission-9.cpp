class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> st;
        for(int i=0; i<nums.size(); i++) {
            if(st[nums[i]] > 0) return true;
            st[nums[i]]++;
        }
        return false;
    }
};