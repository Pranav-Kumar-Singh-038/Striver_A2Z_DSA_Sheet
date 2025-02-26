#include <bits/stdc++.h>
using namespace std;

class Solution { // Binary tree has 2^(n-1) nodes at level n.
    public:
    // TC: O(1), SC: O(1)
      int countNodes(int i) {
          return pow(2,i-1);
      }
  };

int main()
{
    int n;
    cin>>n;
    Solution sol;
    int ans=sol.countNodes(n);
    cout<<ans;
    return 0;
}