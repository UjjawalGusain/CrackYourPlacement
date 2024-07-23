// https://leetcode.com/problems/basic-calculator-ii/description/

class Solution {
public:
    int evaluate(int n1, int n2, char op) {

        switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '/':
            return n1 / n2;
        default:
            return n1 * n2;
        }
        return 0;
    }

    int calculate(string s) {
        stack<char> opStack;
        stack<int> numStack;

        for (int i = s.length() - 1; i >= 0; i--) {
            if(numStack.empty())
                cout << "Empty" << endl;
            else cout << numStack.top() << endl;
            char c = s[i];
            if(c == ' ') continue;
            else if (c == '/' || c == '*') {
                opStack.push(c);
            } else if (c == '+' || c == '-') {
                while (!opStack.empty() &&
                       (opStack.top() == '/' || opStack.top() == '*')) {
                    int n1 = numStack.top();
                    numStack.pop();
                    int n2 = numStack.top();
                    numStack.pop();
                    char op= opStack.top();
                    opStack.pop();
                    int res = evaluate(n1, n2, op);
                    numStack.push(res);
                }
                opStack.push(c);
            } else {
                int j = i;
                while (j >= 0 && s[j] >= '0' && s[j] <= '9')
                    j--;
                int num = stoi(s.substr(j + 1, i - j));
                i = j+1;
                numStack.push(num);
            }
        }

        while (!opStack.empty()) {

            int n1 = numStack.top();
            numStack.pop();
            int n2 = numStack.top();
            numStack.pop();
            char op = opStack.top();
            opStack.pop();
            int res = evaluate(n1, n2, op);
            numStack.push(res);
        }

        return numStack.top();
    }
};