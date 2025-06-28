#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToInfix(string exp) { // since input is postfix, start reading from front, where operands are, when operator found, pop two operands, make infix expression push into stack, and so on, return stk.top()
        // TC: O(n), SC: O(2n)
       stack<string> stk;
       for(int i=0;i<exp.size();i++)
       {
        char ch=exp[i];
        string str(1,ch);
        if(isalnum(ch))
        {
            stk.push(str);
        }
        else
        {
            string opA=stk.top();
            stk.pop();
            string opB=stk.top();
            stk.pop();
            string expression="("+opB+str+opA+")";
            stk.push(expression);
        }
       }
       return stk.top();
        
    }
};

int main()
{
  string s;
  cin>>s;
  Solution sol;
  string ans=sol.postToInfix(s);
  cout<<ans;
  return 0;
}