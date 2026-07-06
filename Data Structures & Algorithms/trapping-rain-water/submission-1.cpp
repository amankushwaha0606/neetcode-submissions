class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), area = 0;
        vector<int> leftHeights(n), rightHeights(n);
        leftHeights[0] = height[0];
        rightHeights[n-1] = height[n-1];
        for(int i=1; i<n; i++) leftHeights[i] = max(height[i], leftHeights[i-1]);
        for(int i=n-2; i>=0; i--) rightHeights[i] = max(height[i], rightHeights[i+1]);

        for(int i=0; i<n; i++) {
            cout << rightHeights[i] << " - " << leftHeights[i] <<  " - " << height[i] << " | ";
            area += min(rightHeights[i], leftHeights[i]) - height[i];
        }

        return area;
    }
};
