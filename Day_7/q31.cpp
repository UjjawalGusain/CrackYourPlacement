// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string res;
        while(true) {
            if(strs[0].size() == 0) return "";
            char ch = strs[0][i];
            for(string &s : strs) {
                if(s.size() == i || s[i] != ch) {
                    return res;
                }
            }
            i++;
            res.push_back(ch);
        }
        return res;
    }
};