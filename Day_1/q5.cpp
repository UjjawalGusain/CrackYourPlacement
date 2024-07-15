// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = -1;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                k++;
                nums[k] = nums[i];
            }
        }
        while(k < nums.size()-1) {
            k++;
            nums[k] = 0;
        }
    }
};