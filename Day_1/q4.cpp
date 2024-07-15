// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // 1: Set the first element of col and row of every element that is
        // zero, accept for the elements in first col, and for that keep a
        // variable 
        // 2.1: Traverse from bottom right, and check if the elements
        // col's first element or row's first ele is zero, if yes, turn zero
        // 2.2: Or if the variable is true and the element is in first col, turn
        // 0

        bool isFirstColZero = false;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (j == 0) {
                        isFirstColZero = true;
                        matrix[i][0] = 0;
                    }
                    else {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        for(int i = n-1; i>=0; i--) {
            for(int j = m-1; j>=0; j--) {
                if(j == 0) {
                    if(isFirstColZero || matrix[i][0] == 0)
                        matrix[i][j] = 0;
                } 
                else {
                    if(matrix[0][j] == 0 || matrix[i][0] == 0)
                        matrix[i][j] = 0;
                }
            }
        }
    }
};