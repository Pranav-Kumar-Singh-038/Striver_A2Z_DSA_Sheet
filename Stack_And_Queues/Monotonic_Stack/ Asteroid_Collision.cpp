#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids) // the only case when collision happens is that top is positive and current is negative, now if top is smaller pop it  , if both are equal pop and use flag to destroy current, else destroye current only, if current not destroyed push it, convert the stack to a vector and return
    {
        // TC:O(3n), SC:O (2n)
        stack<int> stk; // SC: O(n)

        for (int &asteroid : asteroids) // TC: O(n)
        {
            bool destroyed = false;
            while (!stk.empty() && asteroid < 0 && stk.top() > 0 && destroyed==false) // collision case // TC: O(n)
            {
                if (stk.top() < -asteroid)
                {
                    stk.pop(); // top destroyed
                }
                else if (stk.top() == -asteroid)
                {
                    stk.pop(); // both destroyed
                    destroyed = true;
                }
                else // current destroyed
                {
                    destroyed = true; 
                }
            }

            if (!destroyed)
            {
                stk.push(asteroid);
            }
        }

        vector<int> ans(stk.size());              // SC:O(n)
        for (int i = stk.size() - 1; i >= 0; --i) // TC: O(n)
        {
            ans[i] = stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> asteroids(n);
    for (int &it : asteroids)
    {
        cin >> it;
    }
    Solution sol;
    vector<int> ans = sol.asteroidCollision(asteroids);
    for (int &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}