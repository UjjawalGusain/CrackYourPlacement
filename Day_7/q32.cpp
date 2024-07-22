// https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        if(n <= 2) return true;

        int low = 0, high = n-1;
        while(low < high) {
            if(s[low] == s[high]) 
                low++, high--;
            else
                break;
        }

        if(low >= high) return true;

        low = 0, high = n-1;
        bool found = false;
        while(low < high) {
            if(s[low] == s[high])
                low++, high--;
            else if(!found) {
                found = true;
                low++;
            }
            else {
                break;
            }
        }
        if(low >= high) return true;

        low = 0, high = n-1;
        found = false;
        while(low < high) {
            if(s[low] == s[high])
                low++, high--;
            else if(!found) {
                found = true;
                high--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};