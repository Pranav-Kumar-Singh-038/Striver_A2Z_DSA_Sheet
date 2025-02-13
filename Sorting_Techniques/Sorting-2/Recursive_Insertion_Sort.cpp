#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
void insertionSort(vector<int> &arr, int n) { // Sort the first n-1 elements recursively, then insert the last element into its correct position in the sorted portion
    // TC: O(n^2), SC: O(n) (recursive call stack)
    if (n <= 1) return;

    insertionSort(arr, n - 1);

    int key = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

void insertionSort(vector<int> &arr) {
    insertionSort(arr, arr.size());
}


};

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int &x:vec)
    {
        cin>>x;
    }

    Solution sol;
    sol.insertionSort(vec);

    for(auto it:vec)
    {
        cout<<it<<" ";
    }
}