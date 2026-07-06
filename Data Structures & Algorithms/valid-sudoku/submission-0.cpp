class Solution {
public:

    bool isValid33(vector<vector<char>>& board, int i, int j) {
        unordered_map<char,bool> mp1;
        for(int ii=i;ii<i+3;ii++) {
            for(int jj=j;jj<j+3;jj++) {
                if(board[ii][jj] != '.' && mp1.count(board[ii][jj])) {
                    return false;
                }
                mp1[board[ii][jj]] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++) {
            unordered_map<char, bool> mp1, mp2, mp3;
            for(int j=0;j<9;j++) {
                if((board[i][j] != '.' && mp1.count(board[i][j])) || (board[j][i] != '.' && mp2.count(board[j][i]))) {
                    return false;
                }
                mp1[board[i][j]] = true;
                mp2[board[j][i]] = true;
                if(i%3 == 0 && j%3==0) {
                    if(isValid33(board, i, j)) {
                        continue;
                    } else {
                        return false;
                    }                 
                }
            }
        }

        return true;
    }
};
