class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mi = 1;                        // Smallest possible speed is 1
        int mx = *max_element(piles.begin(), piles.end());  // Max pile size
        int result = mx;

        while (mi <= mx) {
            int mid = mi + (mx - mi) / 2;   // Avoid overflow
            int sum = 0;

            for (int pile : piles) {
                sum += (pile + mid - 1) / mid;  // Ceiling division
            }

            if (sum <= h) {
                result = mid;  // Possible answer, try smaller speed
                mx = mid - 1;
            } else {
                mi = mid + 1;  // Too slow, increase speed
            }
        }

        return result;
    }
};
