#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal) // take the diff using xor, and get the set bits in diff using right shift
    {
        // TC: O(logn), SC: O(1)
        int diff = start ^ goal;
        int count = 0;
        while (diff != 0)
        {
            if (diff & 1)
            {
                count++;
            }
            diff = diff >> 1;
        }
        return count;
    }
};

int main()
{
    int start, goal;
    cin >> start >> goal;

    Solution sol;
    int ans = sol.minBitFlips(start, goal);
    cout << ans;
    return 0;
}