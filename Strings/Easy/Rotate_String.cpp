#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal) // make s double and check if goal is present as substring
    {
        //TC: O(n), SC:O(1)
        if (s.length() != goal.length())
        {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }

    bool rotateString2(string s, string goal) // Rotate till end and check when equal
    {
        // TC: O(n^2), SC: O(1) because erase takes O(n) and push_back takes O(n) in worst case
        string temp = s;

        for (int i = 0; i < s.size(); i++)
        {
            if (temp == goal)
            {
                return true;
            }

            char x = temp[0];
            temp.erase(0, 1); // takes O(n)
            temp.push_back(x);
            // cout<<temp<<endl;
        }
        return false;
    }
};

int main()
{
    string s, goal;
    cin >> s >> goal;

    Solution sol;
    bool ans = sol.rotateString(s, goal);
    cout << ans;
}