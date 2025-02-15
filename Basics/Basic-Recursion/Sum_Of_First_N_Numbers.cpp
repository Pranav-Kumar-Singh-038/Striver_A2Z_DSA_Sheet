#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfSeries(int n) // use formula sum of n natural cubes is square of sum of n natural numbers -> S = [n^2 *(n + 1)^2]/4
    {
        // TC: O(1), SC: O(1)
        int sum = ((n * n) * ((n + 1) * (n + 1))) / 4;
        return sum;
    }

    int sumOfSeries2(int n)
    { // using recursion
        // TC: O(n), SC: O(n)
        long long sum = n * n * n;
        if (n == 0)
        {
            return 0;
        }
        return sum += sumOfSeries(n - 1);
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    long long ans = sol.sumOfSeries(n);
    cout << ans;
}