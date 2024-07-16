// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = 0, n = prices.size();
        if(n == 1) return 0;
        for(int i = 0; i<n; i++) {
            if(i!=0 && prices[i] > prices[i-1]) {
                profit += prices[i] - buy;
            }

            if(i!=n-1 && prices[i] < prices[i+1]) {
                buy = prices[i];
            }
        }
        return profit;
    }
};