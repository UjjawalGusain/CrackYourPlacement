// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        // 1. Find smaller next and prev index

        stack<int> s1, s2;
        s1.push(n);
        s2.push(-1);
        vector<int> nextSmallestEle(n), prevSmallestEle(n);
        for(int i = n-1; i>=0; i--) {
            while(!s1.empty() && s1.top() != n && heights[s1.top()] >= heights[i]) {
                s1.pop();
            }
            if(!s1.empty())    
                nextSmallestEle[i] = s1.top();
            else
                nextSmallestEle[i] = n;
            s1.push(i);
        }

        for(int i = 0; i<n; i++) {
            while(!s2.empty() && s2.top() != -1 && heights[s2.top()] >= heights[i]) {
                s2.pop();
            }
            if(!s2.empty())    
                prevSmallestEle[i] = s2.top();
            else
                prevSmallestEle[i] = -1;
            s2.push(i);
        }


        int maxArea = 0;
        for(int i = 0; i<n; i++) {
            int area = (nextSmallestEle[i] - prevSmallestEle[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};