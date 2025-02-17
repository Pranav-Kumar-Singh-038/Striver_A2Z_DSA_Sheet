#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> get(int a, int b) // a^b gives the number which is different for both, then xorring that with a and b swaps them.
    {
        // TC: O(1), SC: O(1)
        a=a^b;
        b=a^b;
        a=a^b;
        return {a,b};
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    Solution sol;
    pair<int,int> ans=sol.get(a,b);
    cout<<ans.first<<" "<<ans.second;
}