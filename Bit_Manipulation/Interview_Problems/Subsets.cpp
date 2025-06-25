#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums) // let's say the 3 is the size of vector, which in binary means 111, if all elements are taken, if we simply vary 111 from 000, we will get all subsets of a vector of size 3, now to take the subsets whose number is set, we do bit manipulation
    {
        // TC: O(n*2^n), SC: O(n+2^n*n)
        vector<vector<int>> ans; // SC: O(2^n*n)
        int n=nums.size();
        int total= 1<<n;// represents the total number of subsets
        for(int mask=0;mask<total;mask++) // TC: O(2^n)
        {
            vector<int> subset; // SC: O(n)
            for(int i=0;i<n;i++) // TC: O(n)
            {
                if(mask&(1<<i)) // the trick here is that first we generated all numbers from 1 to 1<<n and for each number we get a loop which loops until the  size of vector, and finds the set bits , if bits set, it pushes else not.
                {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
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
    vector<vector<int>> ans = sol.subsets(nums);
    for (vector<int> &row : ans)
    {
        for (int &it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}