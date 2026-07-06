class Solution {
public:

    bool possible = true;
    void dfs(vector<vector<int>>& mp, vector<bool>& visited, vector<int>& ans, int node, vector<bool>& processes) {
        if(!possible || processes[node]) return;
        if(visited[node]) {
            possible = false;
            return;
        }        

        visited[node] = true;
        for(int i=0; i<mp[node].size(); i++) {
            dfs(mp, visited, ans, mp[node][i], processes);
        }

        visited[node] = false;
        processes[node] = true;
        ans.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> visited(numCourses);
        vector<bool> processes(numCourses);
        vector<int> ans;

        vector<vector<int>> mp(numCourses);

        for(auto& temp: prerequisites) {
            mp[temp[0]].push_back(temp[1]);
        }

        for(int i=0; i<numCourses; i++) {
            dfs(mp, visited, ans, i, processes);
        }
        if(possible) return ans;
        return {};

    }
};
