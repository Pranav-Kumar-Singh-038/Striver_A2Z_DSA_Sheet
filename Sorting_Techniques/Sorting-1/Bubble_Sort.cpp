#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &arr) // Compare two swap if left is greater, continue this till end, end one step early everytime as big numbers are being added to last, skip last iteration, if no swaps are made the array was already sorted so stop
    {
        // TC: O(n^2), SC: O(1)
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        { 
            bool swapped = false;
            for (int j = 0; j < n - 1 - i; j++)
            { 
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
        for (auto it : arr)
        {
            cout << it << " ";
        }
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
    return 0;
}