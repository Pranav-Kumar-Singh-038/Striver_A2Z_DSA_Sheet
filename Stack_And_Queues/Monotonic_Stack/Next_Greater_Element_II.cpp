#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums) // what i did here, was just duplicate the nums vector to simulate circular behavior rest is same as NGE
    {
        // TC: O(5n) = O(n), SC: O(5n)= O(n)
        int n = nums.size();
        for (int i = 0; i < n; i++) // TC: O(n)
        {
            nums.push_back(nums[i]); // SC: O(n)
        }
        stack<int> stk;                      // SC: O(n)
        unordered_map<int, int> NGE;         // SC: O(2n)
        for (int i = 2 * n - 1; i >= 0; i--) // TC: O(2n)
        {
            int element = nums[i];
            while (!stk.empty() && stk.top() <= element) // TC: O(2n)
            {
                stk.pop();
            }
            if (stk.empty())
            {
                NGE[i] = -1;
            }
            else
            {
                NGE[i] = stk.top();
            }
            stk.push(element);
        }
        vector<int> ans(n); // SC: O(n)
        for (int i = 0; i < n; i++)
        {
            ans[i] = NGE[i];
        }
        return ans;
    }

    vector<int> nextGreaterElements(vector<int> &nums) // what we did here was not used NGE rather used ans vector directly, didn't double the size of nums vector, saving O(3n) space, for time since we didn't use NGE vector we didn't have to copy at last, saving O(n) time
    {
        // TC: O(4n) = O(n), SC: O(2n) = O(n)
        int n = nums.size();
        vector<int> ans(n, -1); // SC: O(n)
        stack<int> stk; // SC:O(n)

        for (int i = 2 * n - 1; i >= 0; i--) // TC: O(2n)
        {
            int idx = i % n;
            while (!stk.empty() && stk.top() <= nums[idx]) // TC: O(2n)
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                ans[idx] = stk.top();
            }
            stk.push(nums[idx]);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    vector<int> nums(n);
    for (int &it : nums)
    {
        cin >> it;
    }
    vector<int> ans = sol.nextGreaterElements(nums);
    for (int &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}