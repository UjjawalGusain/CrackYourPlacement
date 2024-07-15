// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = -1;
        for(int i = 0; i<nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i-1]) {
                k++;
                nums[k] = nums[i];
            }
        }
        return k+1;
    }
};