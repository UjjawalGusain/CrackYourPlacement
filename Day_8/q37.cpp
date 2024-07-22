// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:

    void helper(string &s, int i, int j) {
        while(i < j) {
            swap(s[i], s[j]);
            i++, j--;
        }
    }

    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int i = 0, j = 0, n = s.size();
        while(i < n) {
            while(i < n && s[i] == ' ') i++;
            j = i;
            while(j < n-1 && s[j+1] != ' ') j++;
            helper(s, i, j);
            i = j+1;
        }

        // Removing extra spaces
        i = 0, j = 0;
        while(j < n) {
            
            while(j < n && s[j] == ' ') j++;

            while(j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }

            if(j < n) 
                s[i++] = s[j++];
        }
        i--;
        while(i >=0 && (s[i] == ' ' || s[i] == '\0')) i--;
        s.resize(i+1);

        return s;
    }
};