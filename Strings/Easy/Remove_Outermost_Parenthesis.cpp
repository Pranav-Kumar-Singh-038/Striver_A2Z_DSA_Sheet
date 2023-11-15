#include <bits/stdc++.h>
using namespace std;

// Optimal
class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string res;
        int counter = 0;
        for (char c : S)
        {
            if (c == '(')
            {
                if (counter > 0)
                {
                    res += c;
                }
                counter++;
            }
            if (c == ')')
            {
                if (counter > 1)
                {
                    res += c;
                }
                counter--;
            }
        }
        return res;
    }
};

// First Attempt
// TC: O(n*k), where n is the length of string and k is the number of primitive decompostion
// SC: O(k),
//  beats 56% in runtime, 10% in memory
//  class Solution
//  {
//  public:
//      string removeOuterParentheses(string s)
//      {
//          int count1=0,count2=0;
//          vector<string> vec;
//          string x="";
//          string ans="";
//          for(int i=0;i<s.size();i++)
//          {
//              x+=s[i];
//              if(s[i]=='(')
//              {
//                  count1++;
//              }
//              else
//              {
//                  count2++;
//              }
//              if(count1==count2)
//              {
//                  vec.push_back(x);
//                  x="";
//              }
//          }
//          for(int i=0;i<vec.size();i++)
//          {
//              for(int j=1;j<vec[i].size()-1;j++)
//              {
//               ans+=vec[i][j];
//              }
//          }
//          return ans;
//      }
//  };

int main()
{
    string s;
    cin >> s;
    Solution sol;
    string ans = sol.removeOuterParentheses(s);
    cout << ans;
}