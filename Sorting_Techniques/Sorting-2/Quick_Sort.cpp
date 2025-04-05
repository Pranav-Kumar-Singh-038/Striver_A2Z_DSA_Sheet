#include <bits/stdc++.h>
using namespace std;

// TC Explanation
/*
First partition takes n comparisons to rearrange elements.
Then two subarrays of size n/2 each → each takes n/2 work.
Then n/4, n/8, ... and so on.
*/

class Solution
{
public:
    void quickSort(vector<int> &arr, int low, int high) // select a pivot(largest), swap all the elements smaller than the pivot to the left of the pivot, do this task recursively on both the left and right of the pivot
    {
        // TC: O(nlogn (average)), n^2 (worst) (by selecting largest pivot), nlogn(best), SC: O(1)
        if(low<high)
        {
            int pivot=partition(arr,low,high);
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
       return;
    }

    int partition(vector<int> &arr, int low, int high)
    {
        int pivot=arr[high];
        int i=low-1;
        for(int j=low;j<high;j++)
        {
            if(arr[j]<=pivot)
            {
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
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
    sol.quickSort(vec, 0, vec.size()-1);
    for (auto &it : vec)
    {
        cout << it << " ";
    }
    return 0;
}