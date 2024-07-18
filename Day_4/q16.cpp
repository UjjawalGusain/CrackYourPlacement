// https://leetcode.com/problems/subarray-sum-equals-k/description/

// n^2
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        if(nums[0] == k) res++;
        for(int i = 1; i<n; i++) {
            nums[i] += nums[i-1];
            if(nums[i] == k) res++;
        }

        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[i] - nums[j] == k) res++;
            }
        }

        return res;
    }
};

// TC: O(n), SC: O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> m;
        if(nums[0] == k) res++;
        for(int i = 1; i<n; i++) {
            nums[i] += nums[i-1];
            if(nums[i] == k) res++;
        }
        m[nums[0]] = 1;
        for(int i = 1; i<n; i++) {
            int target = nums[i] - k;
            res += m[target];

            m[nums[i]]++;
        }

        return res;
    }
};