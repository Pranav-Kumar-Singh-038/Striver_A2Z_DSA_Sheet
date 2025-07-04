#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
vector<int> prevSmaller(vector<int> &A);
};

vector<int> Solution::prevSmaller(vector<int> &A) { // do not use unordered_map as it can have duplicate value

    // TC: O(2n) SC:O(2n)
  stack<int> stk;
  vector<int> ans(A.size());
  for(int i=0;i<A.size();i++)
  {
    int element=A[i];
    while(!stk.empty() && element<=stk.top())
    {
        stk.pop();
    }
    if(stk.empty())
    {
        ans[i]=-1;    }
    else
    {
        ans[i]=stk.top();
    }
    stk.push(element);
  }
  return ans;
}


int main()
{
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int &i:vec)
  {
    cin>>i;
  }

  Solution sol;
  vector<int> ans=sol.prevSmaller(vec);
  for(auto &it:ans)
  {
    cout<<it<<" ";
  }
  return 0;
}