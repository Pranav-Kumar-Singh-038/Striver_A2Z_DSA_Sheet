#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertionSort(vector<int> &arr)// assume left to be sorted, iterate sorted part and insert key into its position, to iterate make arr[j+1]=arr[j] finally make arr[j+1]=key where loop breaks,break it when smaller element found or j becomes negative
    {
        // TC: O(n^2), SC: O(1)
        for (int i = 1; i < arr.size(); i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
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
    sol.insertionSort(vec);
    return 0;
}