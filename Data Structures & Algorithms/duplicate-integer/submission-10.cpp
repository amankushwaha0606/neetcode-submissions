class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> st;
        int l =nums.size();
        for(int i=0; i<l; i++) {
            if(st[nums[i]] > 0) return true;
            st[nums[i]]++;
        }
        return false;
    }
};