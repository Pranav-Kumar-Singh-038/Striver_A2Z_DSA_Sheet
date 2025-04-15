#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int maxLen(vector<int>& arr) { // Prefix sum with hashmap, same as largest subarray with sum k
        // TC: O(n), SC: O(n)  
        int prefixSum=0;
          int subarrayLength=0;
          int n=arr.size();
          unordered_map<int,int> prefixMap; // SC: O(n)
          for(int i=0;i<n;i++) // TC: O(n)
          {
               prefixSum+=arr[i];
           if(prefixMap.find(prefixSum)==prefixMap.end())
           {
             prefixMap[prefixSum]=i;
           }
           if(prefixSum==0)
           {
             subarrayLength=max(subarrayLength,i+1);
           }
           if(prefixMap.find(prefixSum)!=prefixMap.end())
           {
            subarrayLength=max(i-prefixMap[prefixSum],subarrayLength);
           }
          }
          return subarrayLength;
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
    int ans=sol.maxLen(nums);
    cout<<ans;
    return 0;
}

