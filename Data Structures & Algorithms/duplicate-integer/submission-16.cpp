class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        int range = maxVal - minVal + 1;

        // ⚠️ Guard: avoid huge memory allocation
        if (range > 1e7) {
            // fallback to hashing if range too big
            unordered_set<int> st;
            for (int num : nums) {
                if (!st.insert(num).second) return true;
            }
            return false;
        }

        vector<bool> seen(range, false);

        for (int num : nums) {
            int idx = num - minVal; // shift to 0-based index
            if (seen[idx]) return true;
            seen[idx] = true;
        }

        return false;
    }
};