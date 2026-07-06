class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = strs[0];
        string sz = to_string(strs[0].length());
        for(int i=1; i<strs.size(); i++) {
            sz = sz + '.' + to_string(strs[i].size());
            ans = ans + strs[i];
        }
        ans = sz + "#" + ans;
        return ans;
    }

    vector<string> decode(string s) {
        if(s.length() == 0) return {};
        vector<string> ans;
        string word = "";
        vector<int> sz;
        string num = "";
        int i=0;
        while(i < s.size() && s[i] != '#') {
            if(s[i] == '.') {
                sz.push_back(stoi(num));
                num = "";
            } else {
                num += s[i];
            }
            i++;
        }
        sz.push_back(stoi(num)); // Push last size
        i++;
        for(int sizee: sz) {
            ans.push_back(s.substr(i, sizee));
            i += sizee;
        }
        return ans;
    }
};
