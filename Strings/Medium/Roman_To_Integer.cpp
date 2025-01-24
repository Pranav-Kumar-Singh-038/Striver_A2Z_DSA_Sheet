#include <bits/stdc++.h>
using namespace std;

class Solution
{
// TC :O(n) ; SC : O(1)
public:
    int romanToInt(string s)
    {
        int val = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
            {

                if (s[i+1] == 'X')
                {
                    val += 9;
                    i++;
                }
                else if (s[i+1] == 'V')
                {
                    val += 4;
                    i++;
                }
                else
                {
                    val += 1;
                }
            }
            else if (s[i] == 'X')
            {
                if (s[i+1] == 'C')
                {
                    val += 90;
                    i++;
                }
                else if (s[i+1] == 'L')
                {
                    val += 40;
                    i++;
                }
                else
                {
                    val += 10;
                }
            }
            else if (s[i] == 'C')
            {
                if (s[i+1] == 'M')
                {
                    val += 900;
                    i++;
                }
                else if (s[i+1] == 'D')
                {
                    val += 400;
                    i++;
                }
                else
                {
                    val += 100;
                }
            }
            else
            {
                if (s[i] == 'V')
                {
                    val+=5;
                }
                else if (s[i] == 'L')
                {
                    val+=50;
                }
                else if (s[i] == 'D')
                {
                    val+=500;
                }
                else if (s[i] == 'M')
                {
                    val+=1000;
                }
            }
        }
    return val;
    }


// TC: O(n) ; SC : O(1)
// This is more readable
    int romanToIntOptimal(string s) {
        unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    int ans = sol.romanToIntOptimal(s);
    cout << ans << endl;
}