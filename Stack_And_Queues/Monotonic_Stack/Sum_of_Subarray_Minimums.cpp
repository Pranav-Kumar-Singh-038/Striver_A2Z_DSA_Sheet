#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    vector<int> computeLeft(vector<int> &arr)
    {
        vector<int> Left(arr.size());        // accounted
        stack<pair<int, int>> stk;           // SC: O(n)
        for (int i = 0; i < arr.size(); i++) // TC: O(n) = TC: O(2n) total
        {
            int count = 1;
            int element = arr[i];
            while (!stk.empty() && stk.top().first > element) // TC: O(n)
            {
                count += stk.top().second;
                stk.pop();
            }
            stk.push({element, count});
            Left[i] = count;
        }
        return Left;
    }

    vector<int> computeRight(vector<int> &arr)
    {
        vector<int> Right(arr.size());            // accounted
        stack<pair<int, int>> stk;                // SC: O(n)
        for (int i = arr.size() - 1; i >= 0; i--) // TC: O(n): total = TC: O(2n)
        {
            int count = 1;
            int element = arr[i];
            while (!stk.empty() && stk.top().first >= element) // TC: O(n) // hrere >= denotes the edge case
            {
                count += stk.top().second;
                stk.pop();
            }
            stk.push({element, count});
            Right[i] = count;
        }
        return Right;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        // TC: O(5n), SC: O(4n)
        int sum = 0;
        vector<int> Left = computeLeft(arr);   // SC: O(2n), TC: O(2n)
        vector<int> Right = computeRight(arr); // SC: O(2n), TC :O (2n)
        for (int i = 0; i < arr.size(); i++)   // TC: O(n)
        {
            sum = (sum + 1LL * Left[i] * Right[i] * arr[i]) % mod;
        }
        return sum;
    }
    /* to find the mins subarray sums, rather than generating the
   subarrays, we find the arrays in which arr[i] is minimum and so on for each i, then we simply
   sum+=arr[i]*(number of subarrays in which it is minimum), Now to find the number of subarrays in which
    it is minimum, for each element arr[i], we find the number of element to its left, in which it is
    minimum, similary for the right part, including i. Now lets say a number is min in 2 left parts and
    3 right parts, to find the number of subarrays in which it is minimum we multiply 2*3 = 6 because
    You have 3 shirts and 4 pants → total outfits = 3 × 4 = 12 Here: You have L valid starts and R valid
     ends → total subarrays = L × R, Also the edge case is that if for an arr[i] if there exists another
      arr[i] same value, then you may not include it in either of the arrays, so it would not be counted,
       as if there are 2 same elements in an array in which it is minimum, in that also that is minimum,
       so we need to count it atleast once, which i have done in right. */
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &it : arr)
    {
        cin >> it;
    }
    Solution sol;
    int ans = sol.sumSubarrayMins(arr);
    cout << ans;
    return 0;
}