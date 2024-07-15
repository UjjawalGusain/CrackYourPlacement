// https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = -1, high = nums.size();
        int i = 0;
        while(i < high) {
            if(nums[i] == 0) {
                swap(nums[i], nums[++low]);
                i++;
            } 
            else if(nums[i] == 2) {
                swap(nums[i], nums[--high]);
            }
            else {
                i++;
            }
        }
    }
};