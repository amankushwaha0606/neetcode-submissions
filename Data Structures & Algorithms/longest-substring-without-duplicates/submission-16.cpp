class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        int maxL = 0;
        int start = 0;
        unordered_map<char, int> v;
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            if(v.count(ch) && v[ch] >= start) {
                start = v[ch]+1;
            }
            maxL = max(maxL, i-start+1);
            v[ch] = i;
        }
        return maxL;
    }
};
