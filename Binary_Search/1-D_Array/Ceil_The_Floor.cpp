#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) // find floor and ciel using diff
    {
        // TC: O(n), SC :O(1)
        vector<int> ans(2);
        int currDiff, maxDiff = INT_MAX, minDiff = INT_MIN;
        for (int &it : arr)
        {
            currDiff = x - it;
            if (currDiff > 0)
            {
                maxDiff = min(currDiff, maxDiff);
            }
            else if (currDiff < 0)
            {
                minDiff = max(currDiff, minDiff);
            }
            else
            {
                return {x, x};
            }
        }
        ans[0] = x - maxDiff;
        ans[1] = x - minDiff;
        if (maxDiff == INT_MAX)
        {
            ans[0] = -1;
        }
        if (minDiff == INT_MIN)
        {
            ans[1] = -1;
        }
        return ans;
    }

};

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> vec(n);
    for (int &it : vec)
    {
        cin >> it;
    }

    Solution sol;
    vector<int> ans = sol.getFloorAndCeil(x, vec);
    for (int &x : ans)
    {
        cout << x << " ";
    }
    return 0;
}