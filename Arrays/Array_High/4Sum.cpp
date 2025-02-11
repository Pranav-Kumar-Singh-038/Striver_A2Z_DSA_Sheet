#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// Time Complexity : O(N^3),
// 52 ms

// Space Complexity : O(1), Constant space. Extra space is only allocated for the Vector(output), however the
// output does not count towards the space complexity.
//13.45mb
// Solved using Array(Three Nested Loop) + Sorting. Optimized Approach.
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};
// Time Complexity : O(N^3), 
// runtime: 274ms

// Space Complexity : O(N), Hash Table(set) space.
// memory used: 49.4 mb

// Solved using Array(Three Nested Loop) + Sorting + Hash Table(set).
// class Solution
// {
// public:
//     std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         std::set<std::vector<int>> set;
//         std::vector<std::vector<int>> output;
//         for (int i = 0; i < n - 3; i++)
//         {
//             for (int j = i + 1; j < n - 2; j++)
//             {
//                 long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
//                 int low = j + 1, high = n - 1;
//                 while (low < high)
//                 {
//                     if (nums[low] + nums[high] < newTarget)
//                     {
//                         low++;
//                     }
//                     else if (nums[low] + nums[high] > newTarget)
//                     {
//                         high--;
//                     }
//                     else
//                     {
//                         set.insert({nums[i], nums[j], nums[low], nums[high]});
//                         low++;
//                         high--;
//                     }
//                 }
//             }
//         }
//         for (auto it : set)
//         {
//             output.push_back(it);
//         }
//         return output;
//     }
// };

// My approach
//  Time Complexity : O(N^4), Here Four nested loop creates the time complexity. Where N is the size of the
//  array(nums).
//  Space Complexity : O(N), Hash Table(set) space.
//  Note : this will give TLE.
//  class Solution
//  {
//  public:
//      std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
//      {
//             int n = nums.size();
//             sort(nums.begin(), nums.end());
//                     std::set<std::vector<int>> s;
//          std::vector<std::vector<int>> vec;
//          if (nums.size() < 4)
//          {
//              return vec;
//          }

//         for (int i = 0; i < n - 3; i++)
//         {
//             for (int j = i + 1; j < n - 2; j++)
//             {
//                 for (int k = j + 1; k < n - 1; k++)
//                 {
//                     for (int l = k + 1; l < n; l++)
//                     {
//                         if((long long)nums[i] + (long long)nums[j] + (long long)nums[k] +
//                         (long long)nums[l] == target)
//                         {
//                             s.insert({nums[i], nums[j], nums[k], nums[l]});
//                         }
//                     }
//                 }
//             }
//         }
//         for (auto it : s)
//         {
//             vec.push_back(it);
//         }
//         return vec;
//     }
// };

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec;
    while (n--)
    {
        int x;
        std::cin >> x;
        vec.push_back(x);
    }
    int target;
    std::cin >> target;
    Solution sol;
    std::vector<std::vector<int>> ans = sol.fourSum(vec, target);
    for (auto it : ans)
    {
        // sort(it.begin(),it.end());
        for (int i = 0; i < it.size(); i++)
        {
            std::cout << it[i] << " ";
        }
        std::cout << "\n";
    }
}