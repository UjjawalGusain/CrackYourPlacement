// https://leetcode.com/problems/3sum/description/

// n^2 with nlogn space complexity
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> m;
        set<vector<int>> s;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            m[-nums[i]] = i;
        }
        
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(m.find(nums[i] + nums[j]) != m.end()) {
                    int first = nums[i], second = nums[j], third = -(nums[i] + nums[j]);
                    int index = m[nums[i] + nums[j]];

                    if(i!=index && j!=index) {
                        vector<int> v = {first, second, third};
                        sort(v.begin(), v.end());
                        s.insert(v);
                    }
                }
            }
        }

        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};


// n^2 with constant space complexity
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            int low = i+1, high = n-1;
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int target = -nums[i];
            while(low < high) {
                int sum = nums[low] + nums[high];
                if(sum == target) {
                    res.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    while(low < high && low>0 && nums[low-1]==nums[low]) low++;
                }
                else if(sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }

        return res;
    }
};