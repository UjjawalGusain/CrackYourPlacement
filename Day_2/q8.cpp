// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m[nums[0]] = 0;
        for(int i = 1; i<nums.size(); i++) {
            int goal = target - nums[i];
            if(m.find(goal) != m.end()) {
                return {m[goal], i};
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};