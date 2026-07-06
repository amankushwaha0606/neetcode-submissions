class Solution {
public:
    int calcArea(vector<vector<int>>& grid, int i, int j, int sum) {
        if(i >= grid.size() || i<0) return sum;
        if(j >= grid[0].size() || j<0) return sum;
        if(grid[i][j] == 0) return sum;
        if(grid[i][j] == 1) {
            sum += 1;
        }
        grid[i][j] = 0;
        sum = calcArea(grid, i, j-1, sum);
        sum = calcArea(grid, i, j+1, sum);
        sum = calcArea(grid, i-1, j, sum);
        sum = calcArea(grid, i+1, j, sum);
        cout << sum << endl;
        return sum;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSum = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                maxSum = max(maxSum, calcArea(grid, i, j, 0));
            }
        }
        return maxSum;
    }
};
