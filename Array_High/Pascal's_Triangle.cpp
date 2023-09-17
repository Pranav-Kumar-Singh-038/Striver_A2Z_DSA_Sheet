#include <bits/stdc++.h>
using namespace std;

// TC : O(n^2)
// SC : O(n^2)
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vec;
        for (int i = 0; i < numRows; i++)
        {
            int val = 1;
            vector<int> nums;
            for (int j = 0; j <= i; j++)
            {
                if (i == 0 || i == 1 || j == 0 || j == i)
                {
                    val = 1;
                }
                else
                {
                    val = vec[i - 1][j - 1] + vec[i - 1][j];
                }
                nums.push_back(val);
            }
            vec.push_back(nums);
        }
        return vec;
    }
};

int main()
{
    int numRows;
    cin >> numRows;
    // cout<<numRows;
    Solution sol;
    vector<vector<int>> ans = sol.generate(numRows);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
