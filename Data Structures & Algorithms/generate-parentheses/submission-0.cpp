class Solution {
public:
    vector<string> ans;

    void makeParen(int n1, int n2, string str) {
        if(n1 > n2 || n1 < 0 || n2 < 0) return;

        if(n1 == 0 && n2 == 0) {
            ans.push_back(str);
            return;
        }

        makeParen(n1-1, n2, str + "(");
        makeParen(n1, n2-1, str + ")");
    }

    vector<string> generateParenthesis(int n) {
        makeParen(n, n, "");
        return ans;
    }
};
