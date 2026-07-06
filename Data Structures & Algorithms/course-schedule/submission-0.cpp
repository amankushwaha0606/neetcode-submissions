class Solution {
public:
    bool dfs(vector<bool>& visited, vector<vector<int>>& mp, int node) {
        if(visited[node]) return false;

        visited[node] = true;

        for(int i=0; i<mp[node].size(); i++) {
            if(!dfs(visited, mp, mp[node][i])) {
                return false;
            }
        }
        visited[node] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> mp(numCourses);
        for(auto& pre: prerequisites) {
            mp[pre[0]].push_back(pre[1]);
        }

        vector<bool> visited(numCourses);

        for(int i=0; i<numCourses; i++) {
            if(!dfs(visited, mp, i)) {
                return false;
            }
        }
        return true;
    }
};
