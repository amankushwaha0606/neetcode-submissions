class Solution {
public:
    bool isPalindrome(string s) {
        int j=s.length()-1;
        int i=0;
        while(i<j){
            char ch1 = s[i];
            char ch2 = s[j];

            if(ch1 >= 'A' && ch1 <= 'Z') {
                ch1 = ch1 - 'A' + 'a';
            }
            if(!((ch1 >= 'a' && ch1 <= 'z') || (ch1 >= '0' && ch1 <= '9'))) {
                i++; continue;
            }

            if(ch2 >= 'A' && ch2 <= 'Z') {
                ch2 = ch2 - 'A' + 'a';
            }
            if(!((ch2 >= 'a' && ch2 <= 'z') || (ch2 >= '0' && ch2 <= '9'))) {
                j--; continue;
            }
            if(ch1 == ch2) {
                i++; j--; continue;
            }
            if(ch1 != ch2) return false;
        }
        return true;
    }
};
