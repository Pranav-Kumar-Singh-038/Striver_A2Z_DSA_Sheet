#include <bits/stdc++.h>
using namespace std;
// 1
// 10 9 ... 1
class Solution
{
public:
    void printTable(int n)
    {
        int final=n*10;
        while (final)
        {
            cout<<final<<" ";
            final=final-n;
        }
        cout << endl;
    }
};

int main()
{
  int n;
  cin>>n;

  Solution sol;
  sol.printTable(n);
}
