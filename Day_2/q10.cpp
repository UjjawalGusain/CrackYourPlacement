// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

// O(n^2)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        if(nums[0] % k == 0) res++;
        for(int i = 1; i<n; i++) {
            nums[i] += nums[i-1];
            if(nums[i] % k == 0) res++;
        }   

        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if((nums[j] - nums[i]) % k == 0) res++;
            }
        }
        return res;
    }
};

// Optimized approach using hashmap and math

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, prefix = 0;
        unordered_map<int, int> m;
        m[0] = 1;

        for(int num: nums) {
            prefix += num;

            int remainder = prefix % k;
            if(remainder < 0) remainder+=k;
            res += m[remainder];
            m[remainder]++; 
        }
        return res;
    }
};