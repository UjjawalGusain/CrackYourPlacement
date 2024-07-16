// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = INT_MAX, n = prices.size();
        for(int i = 0; i<n; i++) {
            if(prices[i] < buy) {
                buy = prices[i];
            } else {
                profit = max(profit, prices[i] - buy);
            }
        }
        return profit;
    }
};