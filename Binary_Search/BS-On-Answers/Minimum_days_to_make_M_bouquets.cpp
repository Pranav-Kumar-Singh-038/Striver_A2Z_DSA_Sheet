#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int countBouquet(int m, int k,vector<int> arr, int mid)
      {
        int pairCount=0;
        int bouquets=0;
        for(auto time:arr) // TC: O(n)
        {
          time-=mid;
          if(time<=0)
          {
            pairCount++;
          }
          else
          {
            pairCount=0;
          }
          if(pairCount==k)
          {
            bouquets++;
            pairCount=0;
          }
        }
        return bouquets;
      }

      int minDaysBloom(int m, int k, vector<int> &arr) { // // We find the max element, then do binary search for max days, which will be in the values 1 to max_element, for each we find the max bouquets if it is greater than required then it is decreased else increased. The twist is that there may be multiple days for which the bouquets is same and ideal so we store the current and continue searching, also if we do not get the exact bouquets we return the higher one (l);
        // TC: O(nlog(max_element)), SC: O(1)
         if(arr.size()<(1LL*m*k))
         {
            return -1;
         }
         int l=1;
         int r=*max_element(arr.begin(),arr.end()); // TC: O(n)
         int mid,ans,bouquets;
         while(l<=r) // TC: (O(nlog(max_element)))
         {
            mid=l+(r-l)/2;
            bouquets=countBouquet(m,k,arr,mid); // TC: O(n)
            if(bouquets==m)
            {
                ans=mid;
                r=mid-1;
            }
            else if(bouquets<m)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
         }  
         if(bouquets==m)
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
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> vec(n);
  for(int &element:vec)
  {
    cin>>element;
  }

  Solution sol;
  int ans=sol.minDaysBloom(m,k,vec);
  cout<<ans;
  return 0;
}