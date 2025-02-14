#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

// Function to compute (x^y) % MOD using Binary Exponentiation
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return (res + p) % p;
}

// Modular Inverse using Fermat's theorem
ll modinv(ll x) { return power(x, MOD - 2, MOD); }

// Function to compute sum of first n natural numbers
ll sum(ll n)
{
    return ((((n % MOD) * ((n + 1) % MOD)) % MOD) * modinv(2)) % MOD;
}

class Solution
{
public:
    ll sumOfDivisors(ll N) // not understand
    {
        // TC: O(sqrt(n)), SC: O(1)
        ll sum = 0;

        for (ll i = 1; i <= sqrt(N); i++)
        {
            // Contribution of i itself
            ll t1 = i * (N / i - i + 1);

            // Contribution of numbers greater than i where i is a divisor
            ll t2 = ((N / i) * (N / i + 1)) / 2 - (i * (i + 1)) / 2;

            sum += t1 + t2;
        }
        return sum;
    }
    // Function to compute sum of divisors using Harmonic Lemma
    ll sumOfDivisors0(ll N) // not understood
    {
        // TC: O(sqrt(n)), SC: O(1)
        ll ans = 0;
        ll l = 1;

        while (l <= N)
        {
            ll k = N / l; // Floor(N / l)
            ll r = N / k; // Maximum value of i where floor(N / i) remains k

            // Using the sum formula to compute contribution
            ans = (ans + (((sum(r) - sum(l - 1) + MOD) % MOD) * k) % MOD) % MOD;

            l = r + 1;
        }
        return ans;
    }

    long long sumOfDivisors1(int n) // For a number i, all its multiples (i, 2i, 3i, ...) will include i as a divisor.
    // So, instead of checking each number separately, we add i to all its multiples in one go. for a number 1 will contribute n/1 times, 2=> n/2 times and so on.
    {
        // TC: O(n), SC: O(1)
        long long totalSum = 0;
        for (int i = 1; i <= n; i++)
        {
            totalSum += (n / i) * i;
        }

        return totalSum;
    }

    long long sumOfDivisors2(int n) // brute force
    {
        // TC:  O(n*sqrt(n)), SC: O(1)
        long long sum = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    if (i / j == j)
                        sum += j;
                    else
                        sum += j + i / j;
                }
            }
        }

        return sum;
    }
};

int main()
{
    ll n;
    cin >> n;
    Solution sol;
    ll ans = sol.sumOfDivisors(n);
    cout << ans;
}