// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int lowCol = 0, highCol = matrix[0].size(), lowRow = 0, highRow = matrix.size();
        int ele = highCol * highRow;
        vector<int> res;
        while( ele ) {
            for(int i = lowCol; ele > 0 && i<highCol; i++) {
                res.push_back(matrix[lowRow][i]);
                ele--;
            }
            lowRow++;

            for(int i = lowRow; ele > 0 && i<highRow; i++) {
                res.push_back(matrix[i][highCol-1]);
                ele--;
            }
            highCol--;

            for(int i = highCol-1; ele > 0 && i>=lowCol; i--) {
                res.push_back(matrix[highRow-1][i]);
                ele--;
            }
            highRow--;

            for(int i = highRow-1; ele > 0 && i>=lowRow; i--) {
                res.push_back(matrix[i][lowCol]);
                ele--;
            }
            lowCol++;
        }
        return res;
    }
};