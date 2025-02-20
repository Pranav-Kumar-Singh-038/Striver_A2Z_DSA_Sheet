#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s) // if opening braces push in stack, else if match pop, otherwise return with false.
    {
        // TC: O(n), SC: O(n)
        stack<char> st;
        for (auto i : s)
        {
            if (i == '(' or i == '{' or i == '[')
            {
                st.push(i);
            }
            else
            {
                if (st.empty() or (st.top() == '(' and i != ')') or (st.top() == '{' and i != '}') or (st.top() == '[' and i != ']'))
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

    bool isValid1(string s) // make an unordered map which contains the correct patterns,
    {                       // take a charecter from the string, make a pair from top of stack, if is a correct pattern , pop it else push it.
        // TC: O(n) where n is size of string. SC: O(n)
        stack<char> stk;
        unordered_map<string, bool> myMap = {{"()", 1}, {"{}", 1}, {"[]", 1}};
        stk.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (!stk.empty())
            {
                string temp = string(1, stk.top()) + string(1, s[i]);
                if (myMap[temp] == 1)
                {
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
            }
            else
            {
                stk.push(s[i]);
            }
        }
        if (stk.empty())
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    bool ans = sol.isValid(s);
    cout << ans;
    return 0;
}