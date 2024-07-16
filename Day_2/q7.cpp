// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long res = INT_MAX;
        for(int i = 0; i<n-m+1; i++) {
            res = min(res, abs(a[i] - a[i+m-1]));
        }
        return res;
    }   
};
