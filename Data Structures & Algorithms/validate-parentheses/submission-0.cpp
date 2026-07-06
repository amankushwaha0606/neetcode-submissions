class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch: s) {
            if(ch == ')' || ch == '}' || ch == ']') {
                if(st.empty()) return false;
                if((st.top() != '(' && ch == ')') || (st.top() != '{' && ch == '}') || (st.top() != '[' && ch == ']')) {
                    return false;
                }
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};
