#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (arr[0] == 0)
        {
            return -1;
        }

        int jumps = 0, farthest = 0, currentEnd = 0;

        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + arr[i]);

            if (i == currentEnd)
            {
                jumps++;
                currentEnd = farthest;

                if (currentEnd >= n - 1)
                {
                    return jumps;
                }
            }
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }

    Solution sol;
    int ans = sol.minJumps(vec);
    cout << ans;
    return 0;
}