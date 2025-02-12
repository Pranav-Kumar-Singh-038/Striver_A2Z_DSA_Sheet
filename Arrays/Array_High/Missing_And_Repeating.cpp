#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*XOR method, first xor everything
    the real and expected, then divide everything according to the right most
    set bit in XOR because that is the deciding factor to separate the missing and
    repeating, then divide and xor in the two groups, the answers will remain, then
     check which is present in array that will be repeating and other will be missing */
    vector<int> findTwoElement(vector<int> &arr)
    {
        // TC: O(3n), SC: O(1), (no long long is used)
        int n = arr.size();
        int XOR = 0;

        for (int i = 0; i < n; i++)
        {
            XOR ^= arr[i];
            XOR ^= (i + 1);
        }

        int rightmostSetBit = XOR & -XOR;

        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & rightmostSetBit)
            {
                x ^= arr[i];
            }
            else
            {
                y ^= arr[i];
            }

            if ((i + 1) & rightmostSetBit)
            {
                x ^= (i + 1);
            }
            else
            {
                y ^= (i + 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
                return {x, y};
        }
        return {y, x};
    }

    vector<int> findTwoElement1(vector<int> &arr) // Finding two equations and solving for  X (repeating) ,Y (missing)
    {
        // TC: O(2n), SC: O(1) , long long is used
        int n = arr.size();
        long long realSum = accumulate(arr.begin(), arr.end(), 0LL);
        long long expectedSum = (long long)n * (n + 1) / 2;
        long long XMinusY = realSum - expectedSum; // X (repeating) - Y (missing)

        long long realSumSq = 0;
        for (int x : arr)
        {
            realSumSq += (long long)x * x;
        }
        long long expectedSumSq = (long long)n * (n + 1) * (2 * n + 1) / 6;
        long long XsqMinusYsq = realSumSq - expectedSumSq; // X² - Y²

        long long XPlusY = XsqMinusYsq / XMinusY; // (X² - Y²) / (X - Y) = X + Y

        int repeatingNum = (XPlusY + XMinusY) / 2;
        int missingNum = XPlusY - repeatingNum;

        return {repeatingNum, missingNum};
    }

    vector<int> findTwoElement2(vector<int> &arr) // Freq array, count for freqs 2 and 0
    {
        // TC: O(2n), SC: O(n)
        vector<int> freq(arr.size(), 0);
        vector<int> ans(2, 0);
        for (int i = 0; i < arr.size(); i++)
        {
            freq[arr[i] - 1]++;
        }
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] == 2)
            {
                ans[0] = i + 1;
            }
            else if (freq[i] == 0)
            {
                ans[1] = i + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &x : vec)
    {
        cin >> x;
    }

    Solution sol;
    vector<int> ans = sol.findTwoElement(vec);
    for (int &x : ans)
    {
        cout << x << " ";
    }
}