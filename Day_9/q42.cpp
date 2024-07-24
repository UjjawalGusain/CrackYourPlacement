// https://leetcode.com/problems/valid-number/description/

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), countE = 0, countSign = 0, countDecimal = 0;
        int eIndex = -1, decimalIndex = -1;
        unordered_set<char> valid = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'e', 'E', '.', '-', '+'};

        for (int i = 0; i < n; i++) {

            // Handle anything else than valid chars
            if(valid.find(s[i]) == valid.end()) return false;

            // Handle -/+ sign
            if (s[i] == '-' || s[i] == '+') {
                if (countSign == 2)
                    return false;
                if(i == n-1) return false;
                else if (i == 0) {
                    continue;
                } else if (s[i - 1] == 'e' || s[i - 1] == 'E') {
                    continue;
                }
                return false;
                countSign++;
            }

            // Handle e sign
            if (s[i] == 'e' || s[i] == 'E') {
                if (countE == 1)
                    return false;
                if (i == 0 || i == n - 1)
                    return false;

                // Before e
                if(s[i-1] == '.') continue;
                if (!isdigit(s[i - 1]))
                    return false;

                // After e
                if (s[i + 1] == 'e' || s[i + 1] == 'E')
                    return false;
                eIndex = i;
                countE++;
            }

            // Handle decimal sign
            if(s[i] == '.') {
                if(countDecimal == 1) return false;
                countDecimal++;
                if(n == 1) return false;
                if(i == 0) {

                    if(s[i+1] == 'e') return false;
                    continue;
                }
                if((i==0 || !isdigit(s[i-1])) && (i==n-1 || !isdigit(s[i+1]))) return false;
                else if(eIndex != -1) return false;
            }

        }

        if(eIndex < decimalIndex)
            return false;

        return true;
    }
};