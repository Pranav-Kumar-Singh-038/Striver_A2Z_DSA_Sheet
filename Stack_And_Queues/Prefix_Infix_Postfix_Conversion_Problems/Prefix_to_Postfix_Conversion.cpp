#include <bits/stdc++.h>
using namespace std;
//((A-(B/C))*((A/K)-L))
class Solution {
  public:
    string preToIn(string pre_exp)
    {
       stack<string> stk;
       for(int i=pre_exp.size()-1;i>=0;i--)
       {
        char ch=pre_exp[i];
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
            string expression="("+opA+str+opB+")";
            stk.push(expression);
        }
       }
       return stk.top();
    }

    string inToPost(string in_exp)
    {
        stack<char> stk;
        string expression="";
       unordered_map<char,int> precedence=
       {
        {'^',3},
        {'*',2},
        {'/',2},
        {'%',2},
        {'+',1},
        {'-',1},
        {'(',0},
       };
       for(char &ch:in_exp)
       {
        if(isalnum(ch))
        {
         expression+=ch;
        }
        else if(ch=='(')
        {
            stk.push(ch);
        }
        else if(ch==')')
        {
            while(!stk.empty() && stk.top()!='(')
            {
                expression+=stk.top();
                stk.pop();
            }
            if (!stk.empty())
                {
                    stk.pop();
                }
        }
        else
        {
            if(!stk.empty() && precedence[stk.top()]>=precedence[ch])
            {
                while(!stk.empty() && precedence[stk.top()]>=precedence[ch])
                {
                    expression+=stk.top();
                    stk.pop();
                }
            }
            stk.push(ch);
        }
       }
       while(!stk.empty())
       {
        expression+=stk.top();
        stk.pop();
       }
       return expression;
    }

    string preToPost1(string pre_exp) { // I first converted from prefix to infix, than to postfix
        // TC: O(2n), SC: (3n) = O(n), O(n)
       string in_exp=preToIn(pre_exp);
       string post_exp=inToPost(in_exp);
       return post_exp;
    }

    string preToPost(string pre_exp) {// read the string from back, as all the operands are at back in prefix, than push to stack, if found a operator, pop two operands, make a postfix expression, and push to stack again. keep doing it
        // TC: O(n), SC: O(2n)
       stack<string> stk;
       for(int i=pre_exp.size()-1;i>=0;i--)
       {
        char ch=pre_exp[i];
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
            string expression=opA+opB+str;
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
    string ans=sol.preToPost(s);
    cout<<ans;
    return 0;
}