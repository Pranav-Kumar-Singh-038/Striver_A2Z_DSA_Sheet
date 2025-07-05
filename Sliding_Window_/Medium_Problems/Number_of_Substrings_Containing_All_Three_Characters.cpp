#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s) // let's say there is a string bbabc, now the first match is abc at last
    // you store the index of each, a=2,b=3,c=4. Now the minimal match starts from 2, and all valid subarrays
    // which include this and have this as "last" are to the left of it, which are 2+1. we do this for all iteration
    // counting all subarrays.
    {
        // TC:O(n), SC:O(1)
        vector<int> lastSeen(3, -1); // SC:O(1)
        int count = 0;

        for (int i = 0; i < s.length(); ++i) // TC:O(n)
        {
            lastSeen[s[i] - 'a'] = i;

            int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});
            if (minIndex != -1)
            {
                count += minIndex + 1;
            }
        }

        return count;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    int ans = sol.numberOfSubstrings(s);
    cout << ans;
    return 0;
}