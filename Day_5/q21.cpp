// https://leetcode.com/problems/reverse-pairs/description/

class Solution {
public:

    // 1. a reference variable that counts number of pairs
    // 2. merge function will count the pairs

    void merge(vector<int>& nums, int low, int high, int &pairs) {
        int mid = (high - low)/2 + low;
        
        vector<int> left, right;
        for(int i = low; i<=mid; i++)
            left.push_back(nums[i]);
        for(int i = mid+1; i<=high; i++)
            right.push_back(nums[i]);

        int n = left.size(), m = right.size();
        int i = 0, j = 0, k = low;

        while(i < n) {
            while(j < m && (long long)left[i] > 2 * (long long)right[j]) j++;
            pairs += j;
            i++;
        }        
        i = 0, j = 0;

        while(i < n && j < m) {
            if(left[i] < right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }

        while(i < n) {
            nums[k++] = left[i++];
        }

        while(j < m) {
            nums[k++] = right[j++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int &pairs) {
        int mid = (high - low)/2 + low;

        if(low >= high) return;

        mergeSort(nums, low, mid, pairs);
        mergeSort(nums, mid+1, high, pairs);
        merge(nums, low, high, pairs);
    }

    int reversePairs(vector<int>& nums) {
        int pairs = 0;
        mergeSort(nums, 0, nums.size()-1, pairs);
        return pairs;
    }
};