#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Explanation of space complexity
    /*  1st 5 primes: 2 × 3 × 5 × 7 × 11 = 2310

      1st 8 primes: 2 × 3 × 5 × 7 × 11 × 13 × 17 × 19 ≈ 9,699,690

  So if a number had 8 distinct prime factors, it would have to be at least ~9 million.

  That grows extremely fast.
  🧮 Upper Bound Math:

  To get a rough estimate:
  Let’s assume n ≥ 2^k
  → taking log base 2 both sides:
  log⁡2(n)≥k⇒k≤log⁡2(n)
  log2​(n)≥k⇒k≤log2​(n)

  So:

      The number of distinct prime factors is at most log₂(n) */
    vector<int> primeFac(int n)
    {
        // TC: O(rootn) This is not O(√n × log n) because we don't divide in every iteration — divisions happen only when n is divisible by i, and n gets smaller each time.,
        // SC: O(logn)
        vector<int> ans;
        if (n % 2 == 0)
        {
            ans.push_back(2);
            while (n % 2 == 0)
            {
                n /= 2;
            }
        }
        for (int i = 3; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ans.push_back(i);
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }
        if (n > 1)
        {
            ans.push_back(n);
        }
        return ans;
    }

    vector<int> primeFac1(int n)
    {
        // TC: O(nloglogn + n)
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int p = 2; p * p <= n; p++)
        {
            if (isPrime[p])
            {
                for (int multiple = p * p; multiple <= n; multiple += p)
                {
                    isPrime[multiple] = false;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            if (isPrime[i] && n % i == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    vector<int> ans = sol.primeFac(n);
    for (int &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}