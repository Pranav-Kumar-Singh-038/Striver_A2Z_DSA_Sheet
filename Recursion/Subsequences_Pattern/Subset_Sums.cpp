#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void storeSums(vector<int> &arr, int index, int currSum, vector<int> &ans) // just find all combinations by include and exclude method and push when index exceeds array size
    {
        // TC: O(2^n), SC: O(n)// recursion depth since max array size is n and we move 1 index at a time
        if (index >= arr.size())
        {
            ans.push_back(currSum);
            return;
        }
        // include
        storeSums(arr, index + 1, currSum + arr[index], ans);
        // exclude
        storeSums(arr, index + 1, currSum, ans);

        return;
    }

    vector<int> subsetSums(vector<int> &arr)
    {
        int index = 0, currSum = 0;
        vector<int> ans;
        storeSums(arr, index, currSum, ans);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &it : vec)
    {
        cin >> it;
    }

    Solution sol;
    vector<int> ans = sol.subsetSums(vec);
    for (int &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}