class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s: strs) {
            int n = s.length();
            ans += to_string(n) + "#" + s;
        }
        cout << ans << endl;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int num = 0;
        string str = "";
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(c == '#') {
                int j=1;
                while(num >= j) {
                    str += s[i+j];
                    j++;
                }
                cout << str << endl;
                ans.push_back(str);
                str = "";
                i = i+num;
                num = 0;
            } else {
                cout << num << endl;
                num = num*10 + (c - '0');
            }
        }
        return ans;
    }
};
