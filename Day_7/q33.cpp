// https://leetcode.com/problems/integer-to-roman/description/

class Solution {
public:

    bool startsWith(int num) {
        while(num/10) {
            num/=10;
        }
        if(num == 4 || num == 9) return true;
        return false;
    }

    int subMax(vector<int> &nums, int n) {

        for(int num : nums) {
            if(n - num >= 0)
                return num;
        }
        return 0;

    }

    string intToRoman(int num) {

        unordered_map<int, string> m;
        m[1] = "I";
        m[5] = "V";
        m[10] = "X";
        m[50] = "L";
        m[100] = "C";
        m[500] = "D";
        m[1000] = "M";

        vector<int> normalForms = {1000, 500, 100, 50, 10, 5, 1};
        vector<int> subtractiveForms = {900, 400, 90, 40, 9, 4};

        m[4] = "IV";
        m[9] = "IX";
        m[40] = "XL";
        m[90] = "XC";
        m[400] = "CD";
        m[900] = "CM";

        string roman;

        while(num) {
            bool startsWith4or9 = startsWith(num);

            if(!startsWith4or9) {
                int subtractWith = subMax(normalForms, num);
                roman += m[subtractWith];
                num -= subtractWith;
            }
            else {
                int subtractWith = subMax(subtractiveForms, num);
                roman += m[subtractWith];
                num -= subtractWith;
            }

        }
        return roman;
    }
};