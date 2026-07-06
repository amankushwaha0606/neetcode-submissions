class Solution {
public:

    unordered_set<string> st = {"1", "2", "3", "4", "5", "6", "7", "8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26"};

    int getSets(string& s, int index) {
        if(index == s.size()) return 1;
        int count = 0;

        if(st.count(s.substr(index, 1))) {
            count +=  getSets(s, index+1);
        }

        if(index+1 < s.size() && st.count(s.substr(index, 2))) {
            count += getSets(s, index+2);
        }
        return count;
    }

    int numDecodings(string s) {
        return getSets(s, 0);
    }
};
