#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBit(int n) // first determine which bit is rightmost 0 using loop and right shift, edge case when all bits are 1, then make that 1.
    {
        // TC: O(logn), SC: O(1)
        int num = n;
        int i = 0;
        while ((num & 1) && num!=0)
        {
            num =num>> 1;
            i++;
        }
        int ans = n | (1 << i);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    int ans = sol.setBit(n);
    cout << ans;
    return 0;
}