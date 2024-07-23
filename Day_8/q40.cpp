// https://www.geeksforgeeks.org/problems/word-wrap1646/1

class Solution {
public:
    int dp[505][2005];
    int helper(vector<int> &nums, int i, int rem, int k) {
        
        if(i == nums.size()) return 0;
        
        // We have two cases:
        //      nums[i] > rem => The word is greater than remaining space
        //          This means, we can only put the word in the next line
        //      nums[i] <= rem => The word is less than remaining space
        //          We can either put the word in next line, or in the same line
        if(dp[i][rem] != -1) return dp[i][rem];
        int res = 0;
        if(nums[i] > rem) {
            res = ((rem + 1) * (rem + 1)) + helper(nums, i+1, k - nums[i] - 1, k);
        }
        else {
            int nextLine = ((rem + 1) * (rem + 1)) + helper(nums, i+1, k - nums[i] - 1, k);
            int sameLine = helper(nums, i+1, rem - nums[i] - 1, k);
            
            
            res = min(nextLine, sameLine);
        }
        
        return dp[i][rem] = res;
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, k, k);
    } 
};
