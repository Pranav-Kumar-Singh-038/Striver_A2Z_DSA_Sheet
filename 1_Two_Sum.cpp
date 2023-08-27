#include <bits/stdc++.h>
using namespace std;

//Optimal: one pass hash table
//TC: O(n)
//SC: O(1)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> numMap;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             int complement = target - nums[i];
//             if (numMap.count(complement)) {
//                 return {numMap[complement], i};
//             }
//             numMap[nums[i]] = i;
//         }

//         return {}; // No solution found
//     }
// };

//Optimal: two pass hash table
//TC: O(n)
//SC: O(1)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> numMap;
//         int n = nums.size();

//         // Build the hash table
//         for (int i = 0; i < n; i++) {
//             numMap[nums[i]] = i;
//         }

//         // Find the complement
//         for (int i = 0; i < n; i++) {
//             int complement = target - nums[i];
//             if (numMap.count(complement) && numMap[complement] != i) {
//                 return {i, numMap[complement]};
//             }
//         }

//         return {}; // No solution found
//     }
// };

//My
//TC : O(n^2)
//SC: O(1)
class Solution 
{
 public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int temp;
        vector<int> vec;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
              temp=nums[i]+nums[j];
              if(temp==target)
              {
               vec.push_back(i);
               vec.push_back(j);
               return vec;
              }
            }

        }
         return {};
    }
};

int main()
{
  int n;
  cin>>n;
  vector<int> vec;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    vec.push_back(x);
  }
  int target;
  cin>>target;

  Solution sol;
  vector<int> ans=sol.twoSum(vec,target);
  
  for(auto i:ans)
  {
    cout<<i<<" ";
  }

}