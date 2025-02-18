#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findXOR(int n)
    {
        int mod = n % 4;
        if (mod == 0)
        {
            return n;
        }
        else if (mod == 1)
        {
            return 1;
        }
        else if (mod == 2)
        {
            return n + 1;
        }
        else if (mod == 3)
        {
            return 0;
        }
    }

    int findXOR(int l, int r) // when xorring from 1 to n, for n%4, remainder 0 gives n, 1-> 1, 2-> n+1, 3->0. So we divide problem into two parts [1,l-1] and [1,r]. After getting these we xor the answers, which gives xor [l,r] 
    {
        // TC:O(1), SC: O(1)
        return (findXOR(l - 1) ^ findXOR(r));
    }
};

int main()
{
    int l, r;
    cin >> l >> r;
    Solution sol;
    int ans = sol.findXOR(l, r);
    cout << ans;
    return 0;
}