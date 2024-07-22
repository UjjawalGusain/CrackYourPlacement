// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    long long base = 26;
    long long mod = 1e9+7;

    long long findHash(string& s, int i, int j) {
        long long hash = 0, b = 1;
        for (int k = j; k >= i; k--) {
            hash = (hash + (s[k] - 'a') * b) % mod;
            b = (b * base) % mod;
        }
        return hash;
    }

    bool checkIfMatch(string& s, string& p, int i, int j) {
        int k = 0;
        while (i <= j) {
            if (s[i] != p[k])
                return false;
            i++, k++;
        }
        return true;
    }

    int strStr(string haystack, string needle) {

        long long needleHash = findHash(needle, 0, needle.size() - 1);

        int i = 0, j = needle.size() - 1, n = haystack.size();
        int needleSize = needle.size();
        long long haystackHash = findHash(haystack, i, j);

        if (needleHash == haystackHash) {
            if (checkIfMatch(haystack, needle, i, j))
                return i;
        }
        
        long long multiplyingFactor = 1;
        for (int k = 1; k < needleSize; k++) {
            multiplyingFactor = (multiplyingFactor * base) % mod;
        }

        while (j < n) {
            long long charVal = haystack[i] - 'a';
            haystackHash = (haystackHash - (charVal * multiplyingFactor) % mod + mod) % mod;
            haystackHash = (haystackHash * base) % mod;
            haystackHash = (haystackHash + (haystack[++j] - 'a')) % mod;
            i++;

            if (needleHash == haystackHash) {
                if (checkIfMatch(haystack, needle, i, j))
                    return i;
            }
        }
        return -1;
    }
};