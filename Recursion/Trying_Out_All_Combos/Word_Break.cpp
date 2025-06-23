#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        return canBreak(s, wordDict, 0);
    }

    bool canBreak(const string &s, const vector<string> &wordDict, int start) // what we are doing is checking if the current strings in the dictionary are there in the the required string or not, if the first one is there, we cut the string using substr then do this with the left out string, if further down the line we were not able to cut like TC 4, we come back to the the next word in dictionary and do it again
    {
        // Time Complexity: O(2^n) in worst case (no memoization), where n = s.size() // why 2 ? "Should I cut the string here (and recurse), or should I keep adding more characters?"
        // Space Complexity: O(n) recursion depth
        if (start == s.length())
        {
            return true;
        }

        for (const string &word : wordDict)
        {
            int len = word.length();
            if (start + len <= s.length() && s.substr(start, len) == word)
            {
                if (canBreak(s, wordDict, start + len))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<string> wordDict(n);
    for (auto &it : wordDict)
    {
        cin >> it;
    }
    Solution sol;
    bool ans = sol.wordBreak(str, wordDict);
    cout << ans;
    return 0;
}