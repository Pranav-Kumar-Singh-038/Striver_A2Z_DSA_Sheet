#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printNos(int n) // first call the function recursively to build the stack, the cout so that the last stack gives value first
    {
        // TC: O(n), SC: O(n) (recursive stack space)
        if (n == 0)
        {
            return;
        }
        printNos(n - 1);
        cout << n<<" ";
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    sol.printNos(n);
    return 0;
}