class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num: nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hp;
        for(auto it: mp) {
            hp.push({it.second, it.first});
            if(hp.size() > k) {
                hp.pop();
            }
        }

        vector<int> res;
        while(!hp.empty()) {
            res.push_back(hp.top().second);
            hp.pop();
        };

        return res;
    }
};
