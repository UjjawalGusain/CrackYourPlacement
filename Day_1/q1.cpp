// https://leetcode.com/problems/find-the-duplicate-number/ 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int one = 0, two = 0;
        while(one != two || one == 0) {
            one = nums[one];
            two = nums[nums[two]];
        }
        one = 0;
        while(one != two) {
            one = nums[one];
            two = nums[two];
        }

        return one;
    }
};