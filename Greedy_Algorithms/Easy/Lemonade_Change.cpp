#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    { // store the change in variables if 5 comes increment that,
        // if 10 comes and 5 is available , decrement 5 and inc 10 else return 0, if 20 comes
        // and 1- 10 and 1- 5 is available then decrement them and continue or if 3 5 are there,
        // else return 0;

        // TC: O(n), SC: O(1)
        int change5 = 0, change10 = 0;
        for (int bill : bills)
        {
            if (bill == 5)
            {
                change5++;
            }
            else if (bill == 10)
            {
                if (change5)
                {
                    change5--;

                    change10++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (change10 && change5)
                {
                    change10--;
                    change5--;
                }
                else if (change5 >= 3)
                {
                    change5 -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> bills(n);
    for (int &x : bills)
    {
        cin >> x;
    }

    Solution sol;
    int ans = sol.lemonadeChange(bills);
    cout << ans;
    return 0;
}