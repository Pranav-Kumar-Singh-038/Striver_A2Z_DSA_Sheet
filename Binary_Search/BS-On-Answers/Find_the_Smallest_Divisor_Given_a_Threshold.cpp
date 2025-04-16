#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int calculateSum(vector<int>& nums,int threshold, int mid)
        {
            int sum=0;
            for(int element:nums) // TC: O(n)
            {
                element=ceil((double)element/mid);
                sum+=element;
            }
            return sum;
        }

        int smallestDivisor(vector<int>& nums, int threshold) { // same as Koko eating bananas
          // TC: O(nlog(max_element)), SC: O(1)
          int l=1;
          int r=*max_element(nums.begin(),nums.end()); // TC: O(n)
          int mid,ans,sum;
          while(l<=r) // TC:O(nlog(max_element))
          {
            mid=l+(r-l)/2;
            sum=calculateSum(nums,threshold,mid); // TC: O(n)
            if(sum==threshold)
            {
                ans=mid;
                r=mid-1;
            }
            else if(sum<threshold)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
          } 
          if(sum==threshold)
          {
            return ans;
          }
          else
          {
            return l;
          }
        }
};

int main()
{
  int n,threshold;
  cin>>n>>threshold;
  vector<int> vec(n);
  for(int &element:vec)
  {
    cin>>element;
  }

  Solution sol;
  int ans=sol.smallestDivisor(vec,threshold);
  cout<<ans;
  return 0;
}