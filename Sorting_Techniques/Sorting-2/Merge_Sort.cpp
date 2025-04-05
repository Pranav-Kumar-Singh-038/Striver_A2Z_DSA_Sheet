#include <bits/stdc++.h>
using namespace std;

// TC Explanation
/*Divide Step:
    The array is split into two halves each time.
    This results in a recursion tree of height log₂n
Merge Step:
    At each level of the recursion tree, you merge all n elements once.
    Each merge operation takes O(n) time (in total for that level)
*/

// SC Explanation
/*
    Each merge allocates a temporary vector of size equal to the subarray being merged.
    The depth of recursion is log n, but the memory is not reused between merges.
    So at any moment, the maximum auxiliary space is O(n) (because in the worst case, you’ll merge the whole array into ans of size n).
*/

class Solution
{
public:
    void mergeSort(vector<int> &arr, int l, int r)
    {
        // TC: O(nlogn), SC: O(n)
        if (l >= r)
        {
            return;
        }
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }

    void merge(vector<int> &arr, int l, int mid, int r)
    {
        vector<int> ans;
        int leftSize = mid - l + 1;
        int rightSize = r - mid;
        int i = l;
        int j = mid + 1;
        while ((i <= mid && j <= r))
        {
            if (arr[i] < arr[j])
            {
                ans.push_back(arr[i]);
                i++;
            }
            else
            {
                ans.push_back(arr[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            ans.push_back(arr[i]);
            i++;
        }
        while (j <= r)
        {
            ans.push_back(arr[j]);
            j++;
        }

        for (int i = l; i <= r; i++)
        {
            arr[i] = ans[i - l];
        }
        return;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    Solution sol;
    sol.mergeSort(vec, 0, vec.size() - 1);
    for (auto &it : vec)
    {
        cout << it << " ";
    }
    return 0;
}