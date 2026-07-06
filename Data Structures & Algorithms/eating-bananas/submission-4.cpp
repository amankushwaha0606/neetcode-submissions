class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int mi = 1;
        int mx = -1;

        for(int i=0; i<piles.size(); i++) {
            mx = max(piles[i], mx);
        }

        int mid, last;

        while(mi <= mx) {
            int sum = 0;
            mid = (mx+mi)/2;
            for(int i=0; i<piles.size(); i++) {
                int t = piles[i]%mid == 0 ? piles[i]/mid : piles[i]/mid+1;
                sum += t;
            }
            
            cout << sum << " ";
            if(sum <= h) {
                last = mid;
                mx = mid-1;
            } else {
                mi = mid+1;
            }
        }

        return last;
    }
};
