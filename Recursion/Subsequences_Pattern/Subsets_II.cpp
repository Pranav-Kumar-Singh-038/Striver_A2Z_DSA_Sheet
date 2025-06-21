#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void storeSums(vector<int> &arr, int index, vector<int> &subset, vector<vector<int>> &ans) // similar to combination sum 2 but we have to push all subsets so instead of only pushing when index>arr.size() push at each level, rest is same
    {
        // TC: O(2^n) worst case (backtracking)n the worst case (no duplicates), you generate all subsets:For n elements → 2^n total subsets.+ O(n log n) (sort), SC: 	O(k * 2^n) for result + O(n) recursion, k is the average size of a valid combination. 
        // You generate 2^n subsets in the worst case. Each subset has average size k.
        ans.push_back(subset); // push subset at every level (including empty one)
        for (int i = index; i < arr.size(); i++)
        {
            if (i > index && arr[i] == arr[i - 1]) // the first condition is for index==i==0
            {
                continue;
            }
            subset.push_back(arr[i]);           // i instead of index
            storeSums(arr, i + 1, subset, ans); // i instead of index
            subset.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int index = 0;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        storeSums(nums, index, subset, ans);
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
    vector<vector<int>> ans = sol.subsetsWithDup(vec);
    for (auto &vec : ans)
    {
        for (int &it : vec)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}