#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void printNos(int n)
      { // TC: O(n), SC: O(n)
          if (n == 0)
          {
              return;
          }
          cout << n<<" ";
          printNos(n - 1);
      }
  };

int main()
{
    int n;
    cin>>n;
    Solution sol;
    sol.printNos(n);
    return 0;
}