#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) { // Try to feed the greediest children first and iterate both list with two pointers
            // If a cookie can't satisfy the child move to the next child, if it can move to the next child and cookie with count++.
            // TC: O(nlogn+mlogm + n) = O(nlogn), SC: O(1)
            sort(g.begin(),g.end(),greater<int>());
            sort(s.begin(),s.end(),greater<int>());
            int i=0,j=0,count=0;
            int n=g.size(),m=s.size();
            while(i<n && j<m)
            {
                int greed=g[i];
                int cookieSize=s[j];
                if(cookieSize>=greed)
                {
                    count++;
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
            return count;
        }
    };

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> g(n);
  vector<int> s(m);
  for(int &x:g)
  {
    cin>>x;
  }
  for(int &x:s)
  {
    cin>>x;
  }

  Solution sol;
  int ans=sol.findContentChildren(g,s);
  cout<<ans;
  return 0;
}