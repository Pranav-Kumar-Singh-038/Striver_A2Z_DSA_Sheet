#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string preToInfix(string pre_exp)
    { // read the string from back, when you get an operand, push it on stack, when you get a operator, pop last two operands, place the operator in between, and push back on stack , with brackets, simple
        // TC:O(n), SC:O(n)
        stack<string> stk;                            // SC: O(n), n is pre_exp size
        for (int i = pre_exp.size() - 1; i >= 0; i--) // TC: O(n)
        {
            char ch = pre_exp[i];
            string str(1, ch);
            if (isalnum(ch))
            {
                stk.push(str);
            }
            else // operator
            {
                string opA = stk.top();
                stk.pop();
                string opB = stk.top();
                stk.pop();
                string expression = "(" + opA + str + opB + ")";
                stk.push(expression);
            }
        }
        return stk.top();
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    string ans = sol.preToInfix(s);
    cout << ans << endl;
}