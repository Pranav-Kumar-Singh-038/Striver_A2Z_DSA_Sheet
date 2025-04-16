#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int nthRoot(int n, int m) { // In the range of 1,m as its nth root will be in that range, find if pow(mid,n) is present.
        // TC: O(logn), SC: O(1)
         int l=0;
         int r=m;
         int mid;
         while(l<=r)
         {
            mid=l+(r-l)/2;
            long long power=pow(mid,n);
            // cout<<power<<endl;
            if(power==m)
            {
                return mid;
            }
            else if(power<m)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
         }
         return -1;
      }
};


int main()
{
    int n,m;
    cin>>n>>m;
    
    Solution sol;
    int ans=sol.nthRoot(n,m);
    cout<<ans;
    return 0;
}