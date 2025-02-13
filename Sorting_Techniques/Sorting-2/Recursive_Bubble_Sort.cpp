#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &arr, int n) // two functions as gfg issues, swapping logic implemented in one then we call bubble sort changing the array size so sorted part is left untouched
    {
        // TC: O(n^2) steps is same wether recursion or iteration, SC: O(n) recursive stack space
        if (n == 1)
            return;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }

        bubbleSort(arr, n - 1);
    }

    void bubbleSort(vector<int> &arr)
    {
        bubbleSort(arr, arr.size());
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int &x : vec)
    {
        cin >> x;
    }

    Solution sol;
    sol.bubbleSort(vec);
    for (auto it : vec)
    {
        cout << it << " ";
    }
}