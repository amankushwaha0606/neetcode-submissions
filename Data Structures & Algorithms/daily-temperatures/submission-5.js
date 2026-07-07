class Solution {
    /**
     * @param {number[]} temperatures
     * @return {number[]}
     */
    dailyTemperatures(temperatures) {

        let stck = [];
        let ans = [];

        for(let i=temperatures.length-1; i>=0; i--) {

            while(stck.length > 0 && temperatures[i] >= temperatures[stck[stck.length-1]]) {
                stck.pop();
            }
            if(stck.length == 0) {
                ans[i] = 0;
            } else {
                ans[i] = stck[stck.length-1] - i;
            }
            stck.push(i);
        }

        return ans;
    }
}
