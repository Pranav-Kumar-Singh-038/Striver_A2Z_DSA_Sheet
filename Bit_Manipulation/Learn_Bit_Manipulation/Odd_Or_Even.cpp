#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isEven(int n) // using bitwise operators
    {
        // TC: O(1), SC: O(1)
        bool ans = !(n & 1);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.isEven(n);
    return 0;
}