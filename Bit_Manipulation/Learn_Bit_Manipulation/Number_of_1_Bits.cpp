#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBits(int n) //  & with 1 gives wether the last bit is set or not, now each time we shift right by 1 so that we can count it
    {
        // TC: O(32)= O(1), since max loop run will be till 32 as max int size of 2^31, SC: O(1)
        int ans = 0;
        while (n > 0)
        {
            ans += n & 1;
            n >>= 1;
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    int ans = sol.setBits(n);
    cout << ans;
    return 0;
}