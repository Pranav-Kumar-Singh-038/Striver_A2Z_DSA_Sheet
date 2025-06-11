#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double recPow(double x, int n, bool negative, int count, double ans)
    {
        if (count == n)
        {
            return ans;
        }
        if (!negative)
        {
            ans *= x;
            count++;
        }
        else
        {
            ans /= x;
            count++;
        }
        return recPow(x, n, negative, count, ans);
    }

    double myPow1(double x, int n) // This will give tle, basic approach of handling negatives differently and keep on multiplying
    {
        // TC: O(n), SC: O(n) stack space
        bool negative = false;
        int count = 0;
        double ans = 1;
        if (n < 0)
        {
            negative = true;
            n = abs(n);
        }
        ans = recPow(x, n, negative, count, ans);
        return ans;
    }

    double myPow(double x, int n) // No tle because if the n is even that means we can simply do x*x and raise them to half power, else do x*x raised to n-1 and mult with x
    {
        // TC: O(logn), SC: O(logn) // stack size
        if (n == 0)
        {
            return 1;
        }

        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }

    double fastPow(double x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }

        double half = fastPow(x, n / 2);

        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};

int main()
{
    double x;
    cin >> x;
    int n;
    cin >> n;
    Solution sol;
    double ans = sol.myPow(x, n);
    cout << ans;
    return 0;
}