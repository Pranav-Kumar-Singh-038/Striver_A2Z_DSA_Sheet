#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)// number before the 2 power number often have all bits set, so taking both and give 0.
    {
        // TC: O(1), SC: O(1)
        if(n<=0)
        {
            return 0;
        }
        bool ans= !(n&(n-1))?1:0;
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;

    Solution sol;
    bool ans=sol.isPowerOfTwo(n);
    cout<<ans;
    return 0;
}