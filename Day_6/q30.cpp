// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(m > n) return -1;
        for(int i = 0; i<n; i++) {
            int j = i, k = 0;
            while(haystack[j] == needle[k]) {
                j++, k++;
                if(k == needle.size()) return i;
            }
        }
        return -1;
    }
};