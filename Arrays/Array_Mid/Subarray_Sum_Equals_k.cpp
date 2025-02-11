#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
//Optimal:
//TC: O(n)
//SC: O(n)
class Solution {
public:
int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> mp;
        int sum=0,count=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                count += mp[find];
            }
            mp[sum]++;
        }
        return count;
    }
};
//My
//TC: O(n^2)
//SC: O(1)
// class Solution {
// public:
//     int subarraySum(std::vector<int>& nums, int k) 
//     {
//         int count=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             int sum=0;
//             for(int j=i;j<nums.size();j++)
//             {
//                 sum=sum+nums[j];
//                 if(sum==k)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

int main()
{
  int n;
  std::cin>>n;
  std::vector<int> arr;
  while(n--)
  {
   int x;
   std::cin>>x;
   arr.push_back(x);
  }
  int k;
  std::cin>>k;
  Solution sol;
  int ans=sol.subarraySum(arr,k);
  std::cout<<ans;
}