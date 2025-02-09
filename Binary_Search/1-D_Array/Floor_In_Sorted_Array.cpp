#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFloor(vector<int> &arr, int k) // return high if element not present, as high will either be the element less than the target to get out of the loop or -1 if not present.
    {
     // TC: O(logn), SC: O(1)
        int low,mid,high;
        low=0;
        high=arr.size()-1;
        while(low<=high)
        {
            mid = low + (high - low) / 2;
            if(arr[mid]==k)
            {
                return mid;
            }
            else if(arr[mid]>k)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return high;
    }
    
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(int &x:vec)
    {
        cin>>x;
    }
    Solution sol;
    int ans=sol.findFloor(vec,k);
    cout<<ans;
    return 0;
}
