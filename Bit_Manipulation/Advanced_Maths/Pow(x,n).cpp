#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, long long n) // the idea is that each bit in n represents the powers of two it was made from, i.e the one in 0 place represents, 2^0 times it has to be multiplied once, for 2 it is 2^3 times, so we loop the power in bits, if the bit is set we increase the result by the current which is accumulated at each term by squaring,
    {
        // TC: O(logn), SC: O(1)
        double base = x;
        bool isNegative=n<0?true:false;
        long long power=abs(n);
        double result = 1.0;
        while(power>0)
        {
            if(power&1)
            {
              result*=base;
            }
            base*=base;
            power=power>>1;
        }
        if(isNegative)
        {
            result = 1.0/result;
            return result;
        }
        return result;
    }
};

int main()
{
    double x;
    int n;
    cin >> x >> n;

    Solution sol;
    double ans = sol.myPow(x, n);
    cout << ans;
}