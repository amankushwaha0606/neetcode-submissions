class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int left=0;
        int right=matrix.size()-1;
        int len = matrix[0].size()-1;
        int mid=-1;

        while(left<=right) {
            mid = (left+right)/2;
            if(matrix[mid][0] == target) {
                return true;
            } else if(matrix[mid][0] <= target && matrix[mid][len] >= target) {
                break;
            } else if(matrix[mid][0] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        left=0;
        right=matrix[0].size()-1;
        int newMid=-1;

        while(left<=right) {
            newMid = (left+right)/2;
            if(matrix[mid][newMid] == target) {
                return true;
            } else if(matrix[mid][newMid] > target) {
                right = newMid-1;
            } else {
                left = newMid+1;
            }
        }

        return false;
    }
};
