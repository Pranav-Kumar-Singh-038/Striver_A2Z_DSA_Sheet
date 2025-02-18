#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
vector<int> spf(MAXN + 1, 1);

class Solution
{
public:
    // Calculating SPF (Smallest Prime Factor) for every
    // number till MAXN.
    // Time Complexity : O(nloglogn)
    void sieve()
    {
        // stores smallest prime factor for every number

        spf[0] = 0;
        for (int i = 2; i <= MAXN; i++)
        {
            if (spf[i] == 1)
            { // if the number is prime ,mark
              // all its multiples who havent
              // gotten their spf yet
                for (int j = i; j <= MAXN; j += i)
                {
                    if (spf[j] == 1) // if its smallest prime factor is
                                     // 1 means its spf hasnt been
                                     // found yet so change it to i
                        spf[j] = i;
                }
            }
        }
    }

    // A O(log n) function returning primefactorization
    // by dividing by smallest prime factor at every step
    vector<int> AllPrimeFactors0(int x) // give segmentation fault as sieve is being called everytime
    { // Revise
        // TC: O(logn), SC: O(n)
        sieve();
        set<int> mySet;
        while (x != 1)
        {
            mySet.insert(spf[x]);
            x = x / spf[x];
        }
        return vector<int>(mySet.begin(), mySet.end());
    }

    vector<int> AllPrimeFactors(int N) // The algorithm finds prime factors of a number `N` by first removing all factors of `2`, then checking odd numbers up to `√N`. Any remaining number greater than `1` is prime, ensuring all factors are captured efficiently.
    {
        // TC:O(n^0.5), SC:O(logn)
        vector<int> factors;
        if (N % 2 == 0)
        {
            factors.push_back(2);
            while (N % 2 == 0)
            {
                N /= 2;
            }
        }

        for (int i = 3; i * i <= N; i += 2)
        {
            if (N % i == 0)
            {
                factors.push_back(i);
                while (N % i == 0)
                {
                    N /= i;
                }
            }
        }

        if (N > 1)
        {
            factors.push_back(N);
        }

        return factors;
    }

    vector<int> AllPrimeFactors1(int N)
    { // make a set, start from 2 till n, keep dividing until the number is no longer divisible then move on to next number
        // TC :O(n), since the inner loop runs at most logn times and the outer for n, for 64 the inner will run and not after 2 anytime , similarly for a 73 it will be linear, SC:O(logn)
        set<int> mySet;
        int num = N;
        for (int i = 2; i <= N; i++)
        {
            while (num % i == 0)
            {
                mySet.insert(i);
                num /= i;
            }
        }
        return vector<int>(mySet.begin(), mySet.end());
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    vector<int> ans = sol.AllPrimeFactors(n);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    return 0;
}