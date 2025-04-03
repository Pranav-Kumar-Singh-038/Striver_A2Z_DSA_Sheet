#include <bits/stdc++.h>
using namespace std;

class Solution { 
    public:
      long long count(int n) { // to calculate number of possible graphs, we need number of possible edges as since each edge can either be or not be in the graph, therefore, ans will 2^edges, now edges are always between 2 vertices so we need in how many ways can 2 vertices be taken from n vertices. which is nC2 which is n*(n-1)/2
        // TC: O(1), SC: O(1)
          long long edges=n*(n-1)/2;
          return pow(2,edges);
      }
  };

int main()
{
 int n;
 cin>>n;
 Solution sol;
 int ans=sol.count(n);
 cout<<ans;
}