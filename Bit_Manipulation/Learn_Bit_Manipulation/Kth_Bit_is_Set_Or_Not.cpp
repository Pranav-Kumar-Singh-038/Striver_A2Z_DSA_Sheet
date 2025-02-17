#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkKthBit(int n, int k) // bit operators
    {
        // TC: O(1), SC: O(1);
        bool ans= n & (1<<k);
        return ans;
    }
};

int main()
{
  int n,k;
  cin>>n>>k;

  Solution sol;
  bool ans=sol.checkKthBit(n,k);
  cout<<ans;
  return 0;
}