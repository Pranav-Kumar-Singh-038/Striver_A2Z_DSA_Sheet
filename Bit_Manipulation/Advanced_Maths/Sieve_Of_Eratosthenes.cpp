#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n) // make a  boolean array of size n+1, then assume all to be true i.e prime, then make 0 and 1 not prime, start a loop from 2 till root n, for each number from 2, mark its multiple after 2*2 i.e i*i as false,as they are multiples, upto n, the remaining number are primes, count or print them
    {
        // TC: O(nloglogn + n) + SC:O(n)
        vector<bool> isPrime(n + 1, true); // SC: O(n)
        isPrime[0] = false;
        isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++) 
        {
            if (isPrime[i] == true)
            {
                for (int multiple = i * i; multiple <= n; multiple += i) // Total TC over all i: O(n/i)
                {
                    isPrime[multiple] = false;
                }
                // Inner loop runs roughly n/2 + n/3 + n/5 + ... ≈ O(n log log n) 
                // Total time = ∑ (n / p) over all primes p ≤ n
                //            = n * ∑ (1 / p) over all primes p ≤ n 
                //            ≈ n * log(log n) (merten's theorem)
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) // TC:O(n)
        {
            if (isPrime[i])
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    int ans = sol.countPrimes(n);
    cout << ans;
    return 0;
}