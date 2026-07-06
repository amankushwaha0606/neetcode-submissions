class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> v;
        int maxL = 0;
        int start = 0; // sliding window start
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (v.count(ch) && v[ch] >= start) {
                start = v[ch] + 1; // move start to one after the last occurrence
            }
            v[ch] = i;
            maxL = max(maxL, i - start + 1);
        }
        return maxL;
    }
};
