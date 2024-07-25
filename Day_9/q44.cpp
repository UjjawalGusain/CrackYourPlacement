// https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m1, m2;
        int minI = -1;
        int have = 0, need = 0;

        for(char c : t) {
            m1[c]++;
        }

        need = m1.size();

        int i = 0, j = 0, n = s.size(), minLen = INT_MAX;

        while(i < n && j < n) {

            char c = s[j];

            if(m1.find(c) == m1.end()) {
                j++;
                continue;
            }

            m2[c]++;

            if(m2[c] == m1[c]) {
                have++;
            }

            while(have == need) {
                if(j-i+1 < minLen) {
                    minLen = min(minLen, j-i+1);
                    minI = i;
                }
                char ch = s[i];
                if(m2.find(ch) == m2.end()) {
                    i++;
                    continue;
                } else {
                    m2[ch]--;
                    if(m2[ch] == 0) m2.erase(ch);
                    i++;
                }

                if(m2[ch] < m1[ch])
                    have--;
            } 
            j++;
        }

        if(minI == -1) return "";

        return s.substr(minI, minLen);

    }
};