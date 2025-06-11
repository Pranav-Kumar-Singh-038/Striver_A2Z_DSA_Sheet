#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi1(string s)
    { // Parse the string by trimming spaces, handling optional sign, extracting digits, and clamping the result within 32-bit signed integer bounds.
        // TC: O(n), SC: O(1)
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ')
            i++; // skip leading spaces

        if (i == n)
            return 0; // return if nothing except white space is found

        bool negative = false;
        if (s[i] == '+' || s[i] == '-')
        {
            negative = (s[i] == '-'); // to check the presence of sign flag
            i++;
        }

        long long result = 0;
        while (i < n && isdigit(s[i]))
        {                                        // breaks if a non digit is found
            result = result * 10 + (s[i] - '0'); // decimal logic to find the number
            if (!negative && result > INT_MAX)
                return INT_MAX; // if result is greater or less than int limits we check if it was negative and accordingly invert it
            if (negative && -result < INT_MIN)
                return INT_MIN;
            i++;
        }

        return negative ? -result : result; // same if it was supposed to be negative it inverts then returns it
    }

    int myAtoi(string s) 
    {
        // TC: O(n), SC: O(n)
        int i = 0;
        int n = s.size();
        int ans = 0;
        bool negative = false;
        while ( i < n && s[i] == ' ' )
        {
            i++;
        }
        if(i==n)
        {
            return 0;
        }
        if (s[i] == '-' || s[i] == '+')
        {
            negative = (s[i] == '-') ? true : false;
            i++;
        }

        ans = recursiveAtoi(s, ans, i, negative);
        return ans;
    }

    int recursiveAtoi(string s, long long int ans, int index, bool negative)
    {
        if (index >= s.size() || !isdigit(s[index]))
        {
            if(negative)
            {
                return -1*ans;
            }
            else
            {
            return ans;
            }
        }
        int digit = s[index] - '0';
        ans = ans * 10 + digit;
        if ((ans > INT_MAX && negative == true) || (ans < INT_MIN && negative == false))
        {
            return INT_MIN;
        }
        else if ((ans > INT_MAX && negative == false) || (ans < INT_MIN && negative == true))
        {
            return INT_MAX;
        }

        int num=recursiveAtoi(s,ans,index+1,negative);
        return num;
    }
};
 /*  Preprocess the String Before Recursion
    Trim leading spaces once at the start (not recursively).
    Check and store the sign (+ or -) once and pass it to the recursive function as a parameter.

Define Recursive Function Signature

    Create a helper function like parseDigits(s, index, result, negative) where
        s is the original string,
        index is the current position in the string,
        result is the accumulated number so far,
        negative is a boolean flag.

Recursive Case

    If s[index] is a digit:
        Update result using decimal logic: result = result * 10 + digit.
        Check for overflow, and clamp to INT_MAX or INT_MIN if needed.
        Recur with index + 1.

Base Case

    If index >= s.size() or s[index] is not a digit:
        Return the accumulated result (apply - if negative == true).

Return Final Result

    Start recursion from first digit using parseDigits(...). 
    Return final result from recursion */

/*
Edge Cases -:
Don't access s[i] without checking i < s.size() — prevent out-of-bounds crash.

Handle empty or non-numeric strings after optional sign — return 0.

Avoid using stoi directly — it throws on empty or overflow input.

Clamp values > INT_MAX or < INT_MIN — prevent overflow.

Stop parsing at the first non-digit character after valid digits — don't overread.
*/

int main()
{
    string s;
    cin >> s;
    Solution sol;
    int ans = sol.myAtoi(s);
    cout << ans;
    return 0;
}