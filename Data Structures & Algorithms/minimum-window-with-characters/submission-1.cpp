class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.length() > s.length()) return "";
        unordered_map<char, int> mp;
        for(char c: t) mp[c]++;
        int k = mp.size(), n1 = t.length(), left = 0, i1=0, i2=0, ans=INT_MAX;

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            if(mp.count(ch)) {
                mp[ch]--;
                if(mp[ch] == 0) k--;
            }

            while(i >= left && k == 0) {
                if(ans > i-left+1) {
                    cout << i << " " << left << " " << ans << endl;
                    ans = i-left+1;
                    i1 = left;
                    i2 = i;
                }
                if(mp.count(s[left])) {
                    mp[s[left]]++;
                    if(mp[s[left]] == 1) k++;
                }
                left++;
            }
        }
        if(ans > s.length()) return "";
        return s.substr(i1, i2-i1+1);
    }
};
