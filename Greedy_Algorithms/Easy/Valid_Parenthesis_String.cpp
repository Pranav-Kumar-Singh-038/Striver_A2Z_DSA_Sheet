#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        // TC:O(n), SC:O(1)
        // same idea for a count variable, but rather than having a count
        // we have a range min,max, for ( both min and max go up, for ) both go down
        // for *, min goes down, as for * we can have (,),"" which means -1,+1,0. out of which
        // the minimum is -1, the max goes up, as the max possible is +1, if min goes below
        // 0 which means in that path the ) go beyond the (, so we clamp it 0 ignoring the -1 route
        // we are clamping because we know that max is somewhere above 0, if ever it goes
        // below 0, than that means considering all routes we have ) more, so we return false;
        // at the end the min is 0 it means valid string, as we already clamped all minimum
        // values to 0.
        int min = 0, myMax = 0;

        for (char ch : s) // TC:O(n)
        {
            if (ch == '(')
            {
                min++;
                myMax++;
            }
            else if (ch == ')')
            {
                min--;
                myMax--;
            }
            else
            {
                min--;   // if '*' is ')'
                myMax++; // if '*' is '('
            }

            if (myMax < 0)
            {
                return false;
            }

            min = max(min, 0);
        }

        return min == 0;
    }

    bool checkValidPart(string s, int index, int count)
    {
        // we move across the string for ( we add +1 to count for ) we add -1, if at the end, the count is 0
        // that means for every opening we got a closing, but there is an edge case let's
        // say ())(, although the final answer is 0, but at position 2 we have count -1,
        // so to get around whenver we get count <0, we return false,
        // now to add * in the logic, we go through all combination, for * which are (,),""
        // TC:O(3^n), SC:O(n)
        // suboptimal
        if (count < 0)
        {
            return false;
        }
        if (index == s.size())
        {
            return count == 0;
        }
        if (s[index] == '(')
        {
            return checkValidPart(s, index + 1, count + 1);
        }
        else if (s[index] == ')')
        {
            return checkValidPart(s, index + 1, count - 1);
        }
        else
        { // for (                              for )                                for ""
            return checkValidPart(s, index + 1, count + 1) || checkValidPart(s, index + 1, count - 1) || checkValidPart(s, index + 1, count);
        }
    }

    bool checkValidString1(string s)
    {
        return checkValidPart(s, 0, 0);
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    bool ans = sol.checkValidString(s);
    cout << ans;
}