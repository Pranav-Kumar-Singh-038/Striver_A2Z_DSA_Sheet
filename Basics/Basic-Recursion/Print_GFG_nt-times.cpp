#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printGfg(int N)
    {
        // TC: O(n), SC: O(n)
        if(N==0)
        {
            return;
        }
        cout<<"GFG"<<" ";
        printGfg(N-1);
    }
};

int main()
{
    int n;
    cin>>n;
    Solution sol;
    sol.printGfg(n);
    return 0;
}