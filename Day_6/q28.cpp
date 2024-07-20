// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';


        for(char c : s) {
            // If Bracket closed
            if(m.find(c) != m.end()) {
                if(st.empty()) return false;
                if(st.top() != m[c]) return false;
                st.pop();
            }    
            // If bracket openend
            else {
                st.push(c);
            }
        }
        if(st.empty()) return true;
        return false;
    }
};