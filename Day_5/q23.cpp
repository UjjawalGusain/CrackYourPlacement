// https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], candidateVote = 1, n = nums.size();

        for(int i = 1; i<n; i++) {
            if(nums[i] == candidate) {
                candidateVote++;
            } else {
                candidateVote--;
                if(candidateVote == 0) {
                    candidate = nums[i];
                    candidateVote = 1;
                }
            }
        }
        return candidate;
    }
};