class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    maxArea(heights) {

        let i=0, j=heights.length-1, ans = 0;

        while(i<j) {
            ans = Math.max(ans, Math.min(heights[i], heights[j])*(j-i));
            if(heights[i] < heights[j]) {
                i++
            } else j--;
        }
        return ans;
    }
}
