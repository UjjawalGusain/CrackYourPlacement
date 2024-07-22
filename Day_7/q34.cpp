// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:

    void helper(int open, int close, vector<string> &res, string &s, int n) {
        if(open < close) return;
        if(n == 0 && open == close) {
            res.push_back(s);
            return;
        }
        else if(n==0) return;


        if(open == close) {
            // Only one choice, increase open
            s += "(";
            helper(open+1, close, res, s, n-1);
            s.pop_back();
        }
        else {
            // Here we can either increase open, or increase close

            // increase open
            s += "(";
            helper(open+1, close, res, s, n-1);
            s.pop_back();

            // increase close
            s += ")";
            helper(open, close+1, res, s, n-1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        n *= 2;
        helper(0, 0, res, s, n);
        return res;
    }
};