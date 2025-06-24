#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor) // handle edge case, the int min is -2^31 but int max is 2^31-1 so when you finally return -ans, it may exceed so handle it, division logic is increase divisor by left shifting it, and subtract from dividend, then do it again, ex 10/3, 3 is raised to 6, then subtracted, the power is 1 as 1 left shift, add 1<<power to ans, then it is 4/3, it is again raised,return ans  
    {
        // TC: O(32)= O(1), SC: O(1)
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long upper = abs((long long)dividend);
        long long lower = abs((long long)divisor);
        long long ans = 0;

        while (upper >= lower)
        {
            long long temp = lower;
            int power = 0;

            while ((temp << 1) <= upper)
            {
                temp <<= 1;
                power++;
            }

            upper -= temp;
            ans += 1LL << power;
        }

        if (negative)
        {
            ans = -ans;
        }

        if (ans > INT_MAX)
        {
            return INT_MAX;
        }
        if (ans < INT_MIN)
        {
            return INT_MIN;
        }

        return (int)ans;
    }
};

int main()
{
    int dividend, divisor;
    cin >> dividend >> divisor;

    Solution sol;
    int ans = sol.divide(dividend, divisor);
    cout << ans;
}