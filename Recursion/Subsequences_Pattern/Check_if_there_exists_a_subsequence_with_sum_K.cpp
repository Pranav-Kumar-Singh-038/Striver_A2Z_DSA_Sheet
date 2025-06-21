#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool subSum(int n, vector<int> &arr, int k, int currSum, int index) // return true if found sum, false, also check each time if the function call returned true or false else, each time, take two cases, wether to include the number or not, do this recursively,
    {
        // TC: O(2^n), SC: O(n) // because at each recursive call index increases by 1 and it goes to n max
        if (currSum == k)
        {
            return true;
        }
        if (currSum > k || index >= n)
        {
            return false;
        }

        bool include = subSum(n, arr, k, currSum + arr[index], index + 1);
        if (include == true)
        {
            return true;
        }
        bool exclude = subSum(n, arr, k, currSum, index + 1);
        if (exclude == true)
        {
            return true;
        }
        return false;
    }

    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        int currSum = 0, index = 0;
        bool ans = subSum(n, arr, k, currSum, index);
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    Solution sol;
    bool ans = sol.checkSubsequenceSum(n, vec, k);
    cout << ans;
    return 0;
}