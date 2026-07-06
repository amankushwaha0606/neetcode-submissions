class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(int i=0; i<strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if(mp.count(s)) {
                mp[s].push_back(strs[i]);
            } else {
                mp[s] = {strs[i]};
            }
        }

        for(auto& ss : mp) {
            ans.push_back(ss.second);
        }

        return ans;
    }
};
