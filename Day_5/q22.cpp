// https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/0

class Solution {
  public:
  
    void helper(set<vector<int>> &s, vector<int> &arr, int n, int i) {
     
        if(i == n)
            s.insert(arr);
        for(int j = i; j<n; j++) {
            swap(arr[i], arr[j]);
            helper(s, arr, n, i+1);
            swap(arr[i], arr[j]);
        }
        
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> s;
        helper(s, arr, n, 0);
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};