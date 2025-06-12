#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) // at each iteration, double the base, half the power, works for even case, for odd one simply multiply the current result by base. all while checking if the value is less than MOD
    {
        // TC: O(logn), SC: O(1)
        long long res = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) // For any n, the string is let's say n=5, the string is _ _ _ _ _, now even position can only have 0,2,4,6,8 and odd will have, 1,3,5,7. so for even places 5 possibilities and for odd 4, so total = 5^even possibility*4^odd possibility, but it may exceed 10^9+7 so we make a custom exponential calculator
    {
        // TC: O(logn), SC: O(1)
        long long evenCount = (n + 1) / 2; // positions: 0,2,4...
        long long oddCount = n / 2;        // positions: 1,3,5...
        return (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
    }
};

class Solution1
{
public:
    unordered_set<int> mySet;
    void fillSet()
    {
        mySet.insert({1, 3, 5, 7});
    }

    bool isPrime(int digit) // simply checks if a digit is prime
    {
        // TC:O(1), SC:O(1)
        if (mySet.count(digit))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isGood(string num) // finds if a string is good, ie the even places are divisible by 2 and odd ones are prime
    {
        // TC: O(2*n), SC:O(1)
        for (int i = 0; i < num.size(); i += 2) 
        {
            int digit = num[i] - '0';
            if (digit % 2 != 0)
            {
                return false;
            }
        }
        for (int i = 1; i < num.size(); i += 2)
        {
            int digit = num[i] - '0';
            if (!isPrime(digit))
            {
                return false;
            }
        }
        return true;
    }

    int countFunction(long long n, string num, int count, int ans) // used to count the good numbers in the range to n
    {
        // TC: O(maxNUM*n), where maxNUM:10^n
        int maxNUM = pow(10, n);
        if (count == maxNUM)
        {
            return ans;
        }
        if (isGood(num)) //O(n)
        {
            ans++;
        }
        count++;
        int digit = stoi(num); // TC: O(n)
        digit++;
        stringstream ss;
        ss << setw(n) << setfill('0') << digit;
        num = ss.str(); // To increment the string without losing leading zeroes
        ans = countFunction(n, num, count, ans);
        return ans;
    }

    int countGoodNumbers(long long n)
    {
        // TC: O(maxNUM*n), where maxNUM:10^n, SC: O(1)
        string num(n, '0');
        int count = 0;
        int ans = 0;
        ans = countFunction(n, num, count, ans);         // TC: O(maxNUM*n), where maxNUM:10^n
        return ans;
    }
};

int main()
{
    long long n;
    cin >> n;
    Solution sol;
    // sol.fillSet();
    int ans = sol.countGoodNumbers(n); 
    cout << ans;
    return 0;
}