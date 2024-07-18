// https://leetcode.com/problems/word-search/description/

class Solution {
public:
    int delRow[4] = {0, 0, -1, 1};
    int delCol[4] = {-1, 1, 0, 0};
    bool isWordPresent(vector<vector<char>>& board, string &word, vector<vector<bool>> &visited, int row, int col, int wordIndex) {
        if(wordIndex == word.size()) return true;
        bool isPresent = false;
        visited[row][col] = true;
        for(int k = 0; k<4; k++) {
            int i = row + delRow[k];
            int j = col + delCol[k];

            if(i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j] == word[wordIndex] && !visited[i][j]) {
                if(isWordPresent(board, word, visited, i, j, wordIndex+1)) {
                    return true;
                }
                    
            }
        }
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j<m; j++) {
                if(word[0] == board[i][j]) {
                    if( isWordPresent(board, word, visited, i, j, 1) ) {
                        visited[i][j] = true;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};