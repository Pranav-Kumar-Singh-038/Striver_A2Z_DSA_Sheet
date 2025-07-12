#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // The idea is, you iterate the array, but you keep track of the max
        // index you can reach currently, if at any time the max index you could have reach
        // is lesser than your current position(as you are in a forloop), you return false;
        // else at the end return true;
        // cleaner
        // TC: O(n), SC: O(1)
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > maxReach)
            {
                return false;
            } // stuck
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }

    bool canJump1(vector<int> &nums)
    {
        // TC:O(n), SC:O(1)
        int maxReach = 0;
        int position = 0;
        for (int i = 0; i < nums.size(); i++) // TC:O(n)
        {
            position = i;
            int num = nums[i];
            maxReach = max(maxReach, i + num);
            if (i >= maxReach)
            {
                break;
            }
        }
        if (position == nums.size() - 1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &it : nums)
    {
        cin >> it;
    }
    Solution sol;
    bool ans = sol.canJump(nums);
    cout << boolalpha << ans;
}