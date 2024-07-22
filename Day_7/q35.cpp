// https://leetcode.com/problems/simplify-path/description/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();

        for(int i = 0; i<n; i++) {
            if(path[i] == '/') continue;

            string s;
            while(i < n && path[i] != '/') {
                s.push_back(path[i]);
                i++;
            }

            if(s == ".") {
                continue;
            } else if(s == "..") {
                if(!st.empty())
                    st.pop();
            } else {
                st.push(s);
            }
        }
        string res;
        if(st.empty()) return "/";

        stack<string> st2;
        while(!st.empty()) {
            st2.push(st.top());
            st.pop();
        }

        while(!st2.empty()) {
            res += "/" + st2.top();
            st2.pop();
        }

        return res;

    }
};