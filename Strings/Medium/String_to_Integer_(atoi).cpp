#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int myAtoi(string s) { //Parse the string by trimming spaces, handling optional sign, extracting digits, and clamping the result within 32-bit signed integer bounds.
            // TC: O(n), SC: O(1)
            int i = 0, n = s.size();
            while (i < n && s[i] == ' ') i++; // skip leading spaces
    
            if (i == n) return 0; // return if nothing except white space is found 
    
            bool negative = false;
            if (s[i] == '+' || s[i] == '-') {
                negative = (s[i] == '-'); // to check the presence of sign flag
                i++;
            }
    
            long long result = 0;
            while (i < n && isdigit(s[i])) { // breaks if a non digit is found
                result = result * 10 + (s[i] - '0'); // decimal logic to find the number
                if (!negative && result > INT_MAX) return INT_MAX; // if result is greater or less than int limits we check if it was negative and accordingly invert it
                if (negative && -result < INT_MIN) return INT_MIN;
                i++;
            }
    
            return negative ? -result : result; // same if it was supposed to be negative it inverts then returns it
        }
};
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
 cin>>s;

 Solution sol;
 int ans=sol.myAtoi(s);
 cout<<ans;
 return 0;
}