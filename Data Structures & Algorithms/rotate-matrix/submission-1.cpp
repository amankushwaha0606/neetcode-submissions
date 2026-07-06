class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size()-1;

        for(int i=0; i<=n/2; i++) { 
            for(int j=i; j<n-i; j++){
                // if(n%2 == 0 && j==n/2 && i!=n/2) continue;
                int temp = matrix[n-i][j];
                matrix[n-i][j] = matrix[n-j][n-i];
                matrix[n-j][n-i] = matrix[i][n-j];
                matrix[i][n-j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};
