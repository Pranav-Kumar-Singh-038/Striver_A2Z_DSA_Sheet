#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postToPre(string post_exp)// read from front as it is a postfix expression, keep pushing to stack if operand, if operator, pop two operands, make a prefix expression, and push to stack, keep doing , return stack.top() at end.
    {
        // TC: O(n), SC: O(2n)
        stack<string> stk;
        for(int i=0;i<post_exp.size();i++)
        {
            char ch=post_exp[i];
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
               string expression=str+opB+opA;
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
    string ans=sol.postToPre(s);
    cout<<ans;
    return 0;
}