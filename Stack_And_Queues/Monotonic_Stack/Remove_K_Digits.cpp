#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k) // The core idea is, traverse from left to right, compare two
    //  digits, keep the smaller one, this ensures that the digits at front are smallest possible, which are 
    //  most significant. to achieve this we use a stack or can use a string with pop_back(method)
    // Traverse, if current is smaller than earlier pushed, remove earlier pushed, handle edge case when k>0 at end, which means the digits 
    // 12345, as all in ascending order nothing will be removed, so remove last k digits as the starting ones are already smallest.
    // Also handle edge case when you get leading 0 in answer
    {
        // TC: O(7n), SC O(2n)
        stack<char> stk; // SC: O(n)

        for (char digit : num) // TC: O(n)
        {
            while (!stk.empty() && k > 0 && stk.top() > digit) // TC:O (n)
            {
                stk.pop();
                k--;
            }
            stk.push(digit);
        }

        while (k > 0 && !stk.empty()) // TC: O(n)
        {
            stk.pop();
            k--;
        }

        string result; // SC:O (n)
        while (!stk.empty()) // TC: O(n)
        {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end()); // TC: O(n)

        int nonZero = 0;
        while (nonZero < result.size() && result[nonZero] == '0') // TC: O(n)
        {
            nonZero++;
        }
        result = result.substr(nonZero); // TC:O (n)

        return result.empty() ? "0" : result;
    }
};

int main()
{
    string num;
    cin >> num;
    int k;
    cin >> k;
    Solution sol;
    string ans = sol.removeKdigits(num, k);
    cout << ans;
}