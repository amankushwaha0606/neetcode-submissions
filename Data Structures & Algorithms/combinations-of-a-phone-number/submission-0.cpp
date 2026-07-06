class Solution {
public:

    vector<string> chs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> combs(vector<string> ans, string digits, int i) {
        if(i == digits.size()) return ans;
        int index = digits[i]-'0';
        vector<string> cbn;

        for(int k=0; k<chs[index].size(); k++) {

            char ch = chs[index][k];

            for(int j=0; j<ans.size(); j++) {
                string s = ans[j];

                cbn.push_back(s+ch);
            }
        }

        return combs(cbn, digits, i+1);
        
    }

    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return {};
        return combs({""}, digits, 0);
    }
};
