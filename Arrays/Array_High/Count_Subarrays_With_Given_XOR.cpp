#include <bits/stdc++.h>
using namespace std;

class Solution { // same as prefix sum only difference is when searching for sum-k we search for xor^k also we need to count all subarrays so we maintain a map which stores all subarrays Xor at their indexes, also we maintain prefixMap[0]=1 at start so as to count if arr[0]=k
    public:
      long subarrayXor(vector<int> &arr, int k) {
        // TC: O(n), SC: O(n)
         unordered_map<int,int> prefixMap; // SC: O(n)
         int prefixXOR=0;
         long count=0;
         prefixMap[0] = 1;  
         for(int i=0;i<arr.size();i++) // TC: O(n)
         {
           prefixXOR^=arr[i];
           if(prefixMap.find((prefixXOR^k))!=prefixMap.end())
           {
            count+=prefixMap[prefixXOR^k];
           }
           prefixMap[prefixXOR]++;
         }
         return count;
      }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution sol;
    long ans=sol.subarrayXor(nums,k);
    cout<<ans;
    return 0;
}
