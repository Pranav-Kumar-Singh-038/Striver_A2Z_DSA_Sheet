#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void storeParenthesis1(int n, vector<string> &ans, int startCount, string parenthesis)
    {

        if (parenthesis.size() == 2 * n)
        {
            ans.push_back(parenthesis);
            return;
        }
        int spaceLeft = 2 * n - parenthesis.size();
        if (startCount < n && spaceLeft > startCount)
        {
            storeParenthesis1(n, ans, startCount + 1, parenthesis + '(');
        }
        if (startCount > 0)
        {
            storeParenthesis1(n, ans, startCount - 1, parenthesis + ')');
        }
    }

    vector<string> generateParenthesis1(int n)
    {
        // TC: O(Cₙ × n), SC: O(Cₙ × n)
        vector<string> ans;
        int startCount = 0;
        string parenthesis = "";
        storeParenthesis1(n, ans, startCount, parenthesis);
        return ans;
    }

    void storeParenthesis(int open, int close, string curr, vector<string> &ans)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(curr);
            return;
        }

        if (open > 0)
            storeParenthesis(open - 1, close, curr + '(', ans);

        if (close > open)
            storeParenthesis(open, close - 1, curr + ')', ans);
    }

    vector<string> generateParenthesis(int n)
    {
        // TC: O(Cₙ × n), SC: O(Cₙ × n)
        vector<string> ans;
        storeParenthesis(n, n, "", ans);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);
    for (auto &it : ans)
    {
        cout << it << endl;
    }
    return 0;
}

// Where Cn is the catalan number
/*Cₙ is the n-th Catalan number — a famous sequence in combinatorics that counts the number of ways to:

    Correctly match n pairs of parentheses

    Form full binary trees with n + 1 leaves

    Divide a polygon with n + 2 sides into triangles

    Stack n coins in a valid pyramid shape
    The n-th Catalan number is defined as:
    Catalan number Cₙ = (2n)! / (n! × (n + 1)!)
*/