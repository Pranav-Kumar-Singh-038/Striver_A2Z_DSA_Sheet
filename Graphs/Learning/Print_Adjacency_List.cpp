#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) { // very simple
        // TC: O(n), SC :O(n)
         vector<vector<int>> ans(V);
         for(auto &it:edges)
         {
            ans[it.first].push_back(it.second);
            ans[it.second].push_back(it.first);
         }
         return ans;
      }
  };
  

int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> edges(e);
    for(auto &it:edges)
    {
        cin>>it.first>>it.second;
    }
    Solution sol;
    vector<vector<int>> ans=sol.printGraph(v,edges);
    for(auto &it:ans)
    {
        for(auto &i:it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}