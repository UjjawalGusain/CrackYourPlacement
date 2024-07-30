// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int climbStairs(int n) {
        int oneBack = 2, twoBack = 1;
        if(n==1) return twoBack;
        if(n==2) return oneBack;
        for(int i = 3; i<=n; i++) {
            int newStep = oneBack + twoBack;
            twoBack = oneBack;
            oneBack = newStep;
            cout << oneBack << endl;
        }

        return oneBack;

    }
};