// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            if (dp[i] == true) {
                for (int j = i + 1; j<n && j <= i + nums[i]; j++) {
                    dp[j] = true;
                }
            }
        }
        return dp[n-1];
    }
};