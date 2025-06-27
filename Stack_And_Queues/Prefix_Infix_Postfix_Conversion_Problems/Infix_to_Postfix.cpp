#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string infixToPostfix(string &s)
    {
        // TC: O(2n) because at most all operators can be pushed once to stack, than to output string, SC: O(n)
        unordered_map<char, int> precedence{
            {'^', 3},
            {'*', 2},
            {'/', 2},
            {'%', 2},
            {'+', 1},
            {'-', 1},
            {'(', 0}}; // SC:O(1)

        stack<char> stk; // SC: O(n)
        string postfix = ""; // SC: O(n)

        for (char &ch : s) // TC: O(n)
        {
            if (isalnum(ch))
            {
                postfix += ch;
            }
            else if (ch == '(')
            {
                stk.push(ch);
            }
            else if (ch == ')')
            {
                while (!stk.empty() && stk.top() != '(') 
                {
                    postfix += stk.top();
                    stk.pop();
                }
                if (!stk.empty())
                {
                    stk.pop();
                }
            }
            else 
            {
                while (!stk.empty() && precedence[stk.top()] >= precedence[ch])
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(ch);
            }
        }

        while (!stk.empty())
        {
            postfix += stk.top();
            stk.pop();
        }

        return postfix;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    string ans = sol.infixToPostfix(s);
    cout << ans;
    return 0;
}