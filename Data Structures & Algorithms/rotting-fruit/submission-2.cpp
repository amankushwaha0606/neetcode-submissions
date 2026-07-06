class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int count = 0;
        while(!q.empty() && fresh>0) {
            count++;
            int size = q.size();
            while(size>0) {
                int f = q.front().first;
                int s = q.front().second;
                q.pop();

                for(auto [dx, dy]: dir) {
                    if(f+dx >= 0 && f+dx <grid.size() && s+dy >= 0 && s+dy <grid[0].size() && grid[f+dx][s+dy] == 1) {
                        fresh--;
                        grid[f+dx][s+dy] = 2;
                        q.push({f+dx, s+dy});
                    }
                }
                size--;
            }
        }
        return fresh == 0 ? count : -1;
    }
};
