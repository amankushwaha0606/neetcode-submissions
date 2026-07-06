class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> mp;
        for(char c: s1) mp[c]++;

        int k = mp.size(), n1 = s1.size();

        for(int i=0; i<s2.size(); i++) {
            if(mp.count(s2[i])) {
                mp[s2[i]]--;
                if(mp[s2[i]] == 0) k--;
            }
            if(i-n1 >= 0 && mp.count(s2[i-n1])) {
                mp[s2[i-n1]]++;
                if(mp[s2[i-n1]] == 1) k++;
            }
            if(k == 0) return true;
            
        }
        return false;
    }
};
