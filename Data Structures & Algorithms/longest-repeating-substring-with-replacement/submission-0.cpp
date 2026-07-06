class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int maxf = 0, ans = 0, j=0;

        for(int i=0; i<s.size(); i++) {
            count[s[i]]++;
            maxf = max(maxf, count[s[i]]);

            while((i-j+1) - maxf > k) {
                count[s[j]]--;
                j++;
            }

            ans = max(ans, i-j+1);
        }

        return ans;
    }
};
