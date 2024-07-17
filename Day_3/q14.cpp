// https://leetcode.com/problems/4sum/description/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int j = i+1; j<n; j++) {
                if(j > i+1 && nums[j-1] == nums[j]) continue;
                int low = j+1, high = n-1;
                long goal = (long)target - ((long)nums[i] + (long)nums[j]);
                while(low < high) {
                    long score = (long)nums[low] + (long)nums[high];
                    if(score == goal) {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        while(low < high && nums[low] == nums[low-1]) low++;
                    } else if(score < goal) {
                        low++;
                    } else {
                        high--;
                    }
                }
            }
        }
        return res;
    }
};