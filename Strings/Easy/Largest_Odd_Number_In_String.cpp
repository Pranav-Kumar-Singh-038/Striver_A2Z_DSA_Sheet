#include <bits/stdc++.h>
using namespace std;
// Second Approach
// TC: O(n) SC:O(1)
class Solution
{
public:
    string largestOddNumber(string num)
    {
        int l = 0;
        int r = num.size() - 1;

        while (r >= l && (num[r] - '0') % 2 == 0)
        {
            r--;
        }

        return num.substr(l, r - l + 1);
    }
};
// O(n) beats 83% in runtime
// O(n) beats 18% in memory
// class Solution
// {
// public:
//     string largestOddNumber(string num)
//     {
//         int l = 0;
//         int r = num.size() - 1;
//         string ans = "";
//         if (num.size() == 0)
//         {
//             return "";
//         }
//         else
//         {
//             while (r >= l && (num[r] - '0') % 2 == 0)
//             {
//                 r--;
//             }
//             for (int i = l; i <= r; i++)
//             {
//                 ans += num[i];
//             }
//             return ans;
//         }
//     }
// };

int main()
{
    string num;
    cin >> num;
    Solution sol;
    string ans = sol.largestOddNumber(num);
    cout << ans;
}