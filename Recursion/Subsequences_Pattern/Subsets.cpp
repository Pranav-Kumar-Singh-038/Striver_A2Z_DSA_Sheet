#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void createSubsets(vector<vector<int>> &vec, vector<int> &nums, vector<int> &subset, int index)
    {
        if (index == nums.size())
        {
            vec.push_back(subset);
            return;
        }

        createSubsets(vec, nums, subset, index + 1);
        subset.push_back(nums[index]);
        createSubsets(vec, nums, subset, index + 1);
        subset.pop_back(); // we are basically removing an element after pushing so the vector goes to the previous state before entering the function, essentially resetting it
    }

    vector<vector<int>> subsets(vector<int> &nums) // basic idea is that to make the subset, we can either take an element or not take it, it basically covers all cases.
    {
        /*
        Time	O(2ⁿ × n)
        Space (Auxiliary)	O(n) (for subset + call stack)
        Space (Output)	O(2ⁿ × n) (for storing all subsets)
        */
        vector<vector<int>> ans;
        vector<int> subset;
        createSubsets(ans, nums, subset, 0);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
    {
        cin >> it;
    }
    Solution sol;
    vector<vector<int>> ans = sol.subsets(nums);
    for (auto &vec : ans)
    {
        for (auto &it : vec)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}