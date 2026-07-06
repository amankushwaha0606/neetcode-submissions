class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            if((ch == '(' || ch == '{' || ch == '[')) {
                st.push(ch);
            } else {
                if(st.empty() && (ch == ')' || ch == '}' || ch == ']')) {
                    return false;
                } else if(ch == ')' && st.top() != '(') return false;
                else if(ch == ']' && st.top() != '[') return false;
                else if(ch == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
