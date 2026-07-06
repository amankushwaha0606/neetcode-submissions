class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1;
        int maxWater = 0;
        while(i<j) {
            maxWater = max(maxWater, (j-i)*min(heights[j], heights[i]));
            if(heights[j] < heights[i]) {
                j--;
            } else i++;
        }
        return maxWater;
    }
};
