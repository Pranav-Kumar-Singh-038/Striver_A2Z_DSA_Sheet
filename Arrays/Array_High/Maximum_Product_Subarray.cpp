#include <bits/stdc++.h>
using namespace std;

//TC : O(n); SC : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=*max_element(nums.begin(),nums.end());
        int curr_max=1, curr_min=1;
        for(auto n:nums)
        {
          int new_max=curr_max*n;
          int new_min=curr_min*n;
          curr_max=max({n, new_max, new_min});
          curr_min=min({n, new_max, new_min});

          res=max(curr_max, res);
        }
        return res;
    }
};

int main()
{
  int n;
  cin>>n;
  vector<int> nums;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    nums.push_back(x);
  }
  Solution sol;
  int ans= sol.maxProduct(nums);
  cout<<ans;
}