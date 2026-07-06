class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans = 0;
        vector<int> left(n+2, 0), right(n+2, 0);
        height.push_back(0);
        height.insert(height.begin(), 0);

        for(int i=1; i<n+1; i++) {
            left[i] = max(left[i-1], height[i]);
            right[n-i+1] = max(right[n-i+2], height[n-i+1]);
        }

        for( int i=0; i<n+2; i++) {
            ans += min(left[i], right[i]) - height[i];
        }

        return ans;
    }
};
