class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLongestSubstring(s) {
        
        let mp = new Map();
        let left = 0, ans = 0;
        for(let i=0; i<s.length; i++) {
            while((mp.get(s[i]) || 0) > 0) {
                mp.set(s[left], (mp.get(s[left]) || 0) - 1);
                left++;
            }
            mp.set(s[i], (mp.get(s[i]) || 0)+1);
            ans = Math.max(ans, i-left+1);
        }
        return ans;
    }
}
