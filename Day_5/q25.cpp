// https://leetcode.com/problems/max-value-of-equation/description/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int maxi = INT_MIN;

        for (auto& point : points) {
            int x2 = point[0], y2 = point[1];
            
            while (!pq.empty() && x2 - pq.top().second > k) {
                pq.pop();
            }

            if (!pq.empty()) {
                maxi = max(maxi, pq.top().first + x2 + y2);
            }

            pq.push({y2 - x2, x2});
        }

        return maxi;
    }
};