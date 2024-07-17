// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int low = 0, high = k-1, sum = 0, n = cardPoints.size()-1; 
        for(int i = low; i<=high; i++) 
            sum+=cardPoints[i];
        int currVal = sum;
        for(int i = n; high>=0; i--) {
            currVal = currVal-cardPoints[high]+cardPoints[i];
            sum = max(sum, currVal);
            high--;
        }
        return sum;
    }
};