#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // TC: O(2n) SC: O(1)
        int count[26] = {0};

        for (char x : s)
        {
            count[x - 'a']++;
        }

        for (char x : t)
        {
            count[x - 'a']--;
        }

        for (int val : count)
        {
            if (val != 0)
            {
                return false;
            }
        }

        return true;
    }

    bool isAnagram(string s, string t) // store s frequency and check for t if frequency mismatch
    {
        // TC: O(2n) SC: O(n)
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> myMap;
        for (auto &it : s)
        {
            myMap[it]++;
        }
        for (auto &it : t)
        {
            if (myMap[it] == 0)
            {
                return false;
            }
            else
            {
                myMap[it]--;
            }
        }
        return true;
    }

    bool isAnagram2(string s, string t) // sort and compare
    {
        // TC: O(nlogn), SC: O(1)
        if (s.size() != t.size())
        {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string s, t;
    cin >> s >> t;

    Solution sol;
    bool ans = sol.isAnagram(s, t);
    cout << ans;
}