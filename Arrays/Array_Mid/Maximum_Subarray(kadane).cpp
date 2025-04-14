#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums) // Classic kadane
    {
        int maxSum = nums[0];
        int currSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currSum = max(nums[i], currSum + nums[i]); // same as mine but looks better
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }

    int maxSubArray1(vector<int> &nums)
    {
        // TC: O(n), SC: O(1)
        if (nums.empty())
        {
            return 0;
        }
        int n = nums.size();
        int i = 0;
        while (i < n && nums[i] < 0) // TC: O(n)
        {
            i++;
        }
        if (i == n)
        {
            return *max_element(nums.begin(), nums.end());
        }
        int sum = nums[i];
        int maxSum = sum;
        i++;
        for (i; i < n; i++) // TC: O(n)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &x : vec)
    {
        cin >> x;
    }
    Solution sol;
    int ans = sol.maxSubArray(vec);
    cout << ans;
    return 0;
}