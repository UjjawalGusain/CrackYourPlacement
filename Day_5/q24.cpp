// https://leetcode.com/problems/game-of-life/description/

class Solution {
public:

    int delRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int delCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    void gameOfLife(vector<vector<int>>& board) {
        
        // -1: was 1, became 0
        // -2: was 0, became 1
        // 1: was 1, is 1
        // 0: was 0, is 0
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                int neighbours = 0;
                for(int k = 0; k<8; k++) {
                    int row = i + delRow[k];
                    int col = j + delCol[k];
                    if(row >= 0 && col >= 0 && row < n && col < m ) {
                        if(board[row][col] == -1 || board[row][col] == 1) 
                            neighbours++;
                    }
                }

                if(board[i][j] == 1) {
                    if(neighbours < 2 || neighbours > 3) {
                        board[i][j] = -1;
                    }
                } 
                else {
                    if(neighbours == 3) {
                        board[i][j] = -2;
                    }
                }
            }
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j] == -1) {
                    board[i][j] = 0;
                } else if(board[i][j] == -2) {
                    board[i][j] = 1;
                } 
            }
        }
    }
};