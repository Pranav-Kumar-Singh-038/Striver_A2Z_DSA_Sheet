#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int computeTime(vector<int>& arr, int k) 
      {
        int time=0;
        for(auto pile:arr)
        {
          time+=ceil((double)pile/k);
        }
        return time;
      }

      int kokoEat(vector<int>& arr, int k) { // We find the max element, then do binary search for bananas per hour, which will be in the values 1 to max_element, for each we find the eating time if it is greater the eating time is increased else decreased. The twist is that there may be multiple eating speeds for which the time is same and ideal so we store the current and continue searching, also if we do not get the exact speed we return the higher one (l);
          // TC: O(nlogn + n) = O(nlogn), SC: O(1)
          int l=1;
          int r=*max_element(arr.begin(),arr.end()); // TC: O(n)
          int mid,time;
          int ans;
          while(l<=r) // TC: O(nlogn)
          {
            mid=l+(r-l)/2;
            time=computeTime(arr,mid); // TC: O(n)
            if(time==k)
            {
                ans=mid;
                r=mid-1;
            }
            else if(time<k)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
          }
          if(time==k)
          {
            return ans;
          }
          return l;
      }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int &i:nums)
    {
        cin>>i;
    }

    Solution sol;
    int ans=sol.kokoEat(nums,k);
    cout<<ans;
    return 0;
}