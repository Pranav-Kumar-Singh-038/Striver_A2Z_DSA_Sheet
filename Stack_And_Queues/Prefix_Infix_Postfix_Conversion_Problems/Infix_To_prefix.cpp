#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string inToPre(string in_exp)
    {
        // TC: O(4n)= O(n), SC: O(2n) = O(n)
        reverse(in_exp.begin(), in_exp.end()); // TC: O(n/2)
        for (char &ch : in_exp) // TC: O(n)
        {
            if (ch == '(')
            {
                ch = ')';
            }
            else if (ch == ')')
            {
                ch = '(';
            }
        }
        unordered_map<char, int> precedence{
            {'^', 3},
            {'/', 2},
            {'*', 2},
            {'%', 2},
            {'-', 1},
            {'+', 1},
            {'(', 0},
        };
        stack<char> stk; // SC:O(n)
        string expression; // SC: O(n)
        for (char &ch : in_exp) // TC: O(n) forloop, O(n) popping in and out of stack
        {
            if (ch == '(')
            {
                stk.push(ch);
            }
            else if (ch == ')')
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    expression.push_back(stk.top());
                    stk.pop();
                }
                 if (!stk.empty())
                {
                    stk.pop();
                }
            }
            else if (isalnum(ch))
            {
                expression.push_back(ch);
            }
            else
            {
                while (!stk.empty() && precedence[stk.top()] >= precedence[ch])
                {
                    expression.push_back(stk.top());
                    stk.pop();
                }
                stk.push(ch);
            }
        }
        while (!stk.empty()) // includded
        {
            expression.push_back(stk.top());
            stk.pop();
        }
        reverse(expression.begin(),expression.end()); // TC: O(n/2)
        return expression;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    string ans = sol.inToPre(s);
    cout << ans;
    return 0;
}