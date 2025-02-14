#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> passedBy(int a, int &b) { 
        // TC: O(1), SC: O(1)
          return {a+1,b+2};
      }
  };

int main()
{
    int a,b;
    cin>>a>>b;
    Solution sol;
    vector<int> ans=sol.passedBy(a,b);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}