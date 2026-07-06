class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            int index = 1;
            while (i + index < n && temperatures[i + index] <= temperatures[i]) {
                if (v[i + index] == 0) {
                    index = 0;
                    break;
                }
                index += v[i + index];
            }
            if (index != 0 && i + index < n) {
                v[i] = index;
            }
        }

        return v;
    }
};
