#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums) // XOR everything in one variable, only the single one will remain and Xorring anything with itself is 0.
    {
        // TC: O(n), SC:O(1)
        int ans=0;
        for(auto it:nums)
        {
            ans=ans^it;
        }
        return ans;
    }

    int singleNumber1(vector<int> &nums) // find sum then make a set, then subract everything from the set twice, the answer will remain in negative.
    {
        // TC: O(nlogn), SC: O(n)
        int sum = accumulate(nums.begin(), nums.end(), 0); // O(n)
        set<int> s(nums.begin(), nums.end()); // O(nlogn) // single insertion in set takes O(logn) time
        for (int i : s) // O(n)
        {
            sum = sum - (2 * i);
        }
        return sum * (-1);
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
    int ans = sol.singleNumber(vec);
    cout << ans;
    return 0;
}