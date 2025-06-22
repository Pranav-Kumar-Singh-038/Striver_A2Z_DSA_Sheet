#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    void storePalindromes(string &s, int index, vector<string> &current, vector<vector<string>> &ans) // The solution uses backtracking to explore all possible partitions of the string and adds those where every substring is a palindrome.
    {
        // TC: O(n*2^n), SC: O(n+n*2^n), where n is size of string
        if (index == s.size())
        {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < s.size(); ++i)
        {
            if (isPalindrome(s, index, i)) // TC: O(n)
            {
                current.push_back(s.substr(index, i - index + 1)); // choose
                storePalindromes(s, i + 1, current, ans);          // explore
                current.pop_back();                                // unchoose (backtrack)
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> current;
        storePalindromes(s, 0, current, ans);
        return ans;
    }
};

int main()
{
    string str;
    cin >> str;

    Solution sol;
    vector<vector<string>> ans = sol.partition(str);
    for (auto &vec : ans)
    {
        for (auto &it : vec)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}