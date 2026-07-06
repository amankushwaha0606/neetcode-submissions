class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char ch: s) {
            if(matching.count(ch)) {
                if(st.empty()) return false;
                if((matching[ch] != st.top()) ) {
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
