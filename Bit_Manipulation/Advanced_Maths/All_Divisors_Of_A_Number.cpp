#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print_divisors(int n) // Only difference is that to avoid the use of set we use two vectors, one for storing n/i values and other for i values, then print the big array in descending, and smaller in ascending
    {
        // TC: O(n^0.5), SC: O(2*n^0.5)
        vector<int> smallerDivisors, largerDivisors;

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                smallerDivisors.push_back(i);
                if (i != n / i)
                {
                    largerDivisors.push_back(n / i);
                }
            }
        }

        for (int i : smallerDivisors)
        {
            cout << i << " ";
        }

        for (int i = largerDivisors.size() - 1; i >= 0; i--)
        {
            cout << largerDivisors[i] << " ";
        }
    }

    void print_divisors1(int n) // make a set, start a loop from 1 to root n, if it divides add both the divisor and the  quotient, only exception for i==n/i case.
    {
        // TC: O(n^0.5*log(n)), SC: O(2*(n^0.5))
        set<int> ans;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0 && i != n / i)
            {
                ans.insert(i);     // O(logn)
                ans.insert(n / i); // O(logn)
            }
            else if (n % i == 0 && i == n / i)
            {
                ans.insert(i); // O(logn)
            }
        }
        for (auto it : ans)
        {
            cout << it << " ";
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    sol.print_divisors(n);
    return 0;
}