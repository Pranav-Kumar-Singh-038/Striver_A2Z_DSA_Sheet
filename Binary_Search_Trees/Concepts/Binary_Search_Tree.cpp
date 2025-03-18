#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBSTTraversal(vector<int> &arr) // Inorder Traversal of a BST is always sorted in ascending, and only unique elements.
    {
        // TC: O(n), SC: O(1)
        for (int i = 1; i < arr.size(); i++)
        {
          if(arr[i]<=arr[i-1])
          {
             return false;
          }
        }
        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(auto &it:vec)
    {
        cin>>it;
    }
    Solution sol;
    bool ans=sol.isBSTTraversal(vec);
    cout<<ans;
    return 0;
}