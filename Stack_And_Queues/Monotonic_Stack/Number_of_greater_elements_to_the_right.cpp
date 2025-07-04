#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) // what i am doing is, find the index in array, then iterate to last counting greater elements
    {
        // TC: O(q*n), SC: O(q)
        vector<int> ans;         // SC:O(q)
        for (int &idx : indices) // TC: O(q)
        {
            int i = idx;
            int target = arr[idx];
            int count = 0;
            while (i < n) // TC: O(n)
            {
                int val = arr[i];
                if (target < val)
                {
                    count++;
                }
                i++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> indices(q);
    for (int &it : arr)
    {
        cin >> it;
    }
    for (int &it : indices)
    {
        cin >> it;
    }
    Solution sol;
    vector<int> ans = sol.count_NGE(n, arr, q, indices);
    for (int &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}