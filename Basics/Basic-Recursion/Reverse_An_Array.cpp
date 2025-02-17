#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseArrayRecursive(vector<int> &arr,int i)
    {
        if(i>=arr.size()/2)
        {
          return;
        }
        swap(arr[i],arr[arr.size()-i-1]);
        reverseArrayRecursive(arr,i+1);
    }

    void reverseArray(vector<int> &arr) // Recursive version
    {
        // TC: O(n/2), SC: O(n/2) recursive stack space
        int i=0;
        reverseArrayRecursive(arr,i);
    }

};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &x : vec)
    {
        cin >> x;
    }

    Solution sol;
    sol.reverseArray(vec);

    for(auto it:vec)
    {
        cout<<it<<" ";
    }
}