#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void storeBinaryStrings1(int n, int num, vector<string> &ans)
    {
        // TC: O(n), SC: O(n)
        if (num == pow(2, n)) // TC: O(logn)
        {
            return;
        }
        if (!(num & (num >> 1)))
        {
            string str = (bitset<32>(num)).to_string(); // tc: O(32) = O(1)	SC: O(32) = O(1)
            str = str.substr(32 - n);                   // tc, sc: 	O(n)	O(n)
            ans.push_back(str);
        }
        num++;
        storeBinaryStrings1(n, num, ans);
    }

    vector<string> generateBinaryStrings1(int num)
    { // make vector ans, make recursive function storeBinaryStrings to fill it, take the size, starting number(0), and ans vector in it, every time right shift the number, & check with itself, if 0 it has no consecutive, then convert it to binary, then string and store, base case is when you reach 2^n.
        // TC: O(2^n*n), SC: O(2^n)
        vector<string> ans;
        storeBinaryStrings1(num, 0, ans);
        return ans;
    }

    void storeBinaryStrings(int n, string current, char prev, vector<string> &ans)
    {
        if (n == 0)
        {
            ans.push_back(current);
            return;
        }

        // Option 1: Always add '0'
        storeBinaryStrings(n - 1, current + '0', '0', ans);

        // Option 2: Add '1' only if previous is not '1'
        if (prev != '1')
        {
            storeBinaryStrings(n - 1, current + '1', '1', ans);
        }
    }

    vector<string> generateBinaryStrings(int n)
    {
        vector<string> ans;
        storeBinaryStrings(n, "", '0', ans); // Start with previous bit '0'
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    vector<string> ans = sol.generateBinaryStrings(n);
    for (auto &st : ans)
    {
        cout << st << " ";
    }
}