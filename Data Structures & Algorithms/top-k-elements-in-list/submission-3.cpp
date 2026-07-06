class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;

        for(int num: nums) {
            mp[num]++;
        }

        for(auto p: mp) {
            pq.push({p.second, p.first});
        }

        vector<int> ans;

        while(k>0 && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
