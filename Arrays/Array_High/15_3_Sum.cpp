#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

// Optimal Approach-:
// TC : O(n^2) : 73ms
// SC : O(n) : 24.31mb

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int target = -nums[i];
                int l = i + 1, r = n - 1;

                while (l < r) {
                    int sum = nums[l] + nums[r];

                    if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        res.push_back({nums[i], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;
                    }
                }
            }
        }

        return res;
    }
};


// First Approach-:
// TC : O(n^2) : 1290ms
// SC : O(n) : 193.83mb
// class Solution
// {
// public:
//   std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
//   {
//     std::vector<std::vector<int>> vec;
//     std::set<std::vector<int>> s;
//     std::sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size(); i++)
//     {
//       int target = -nums[i];
//       int left = i + 1;
//       int right = nums.size() - 1;
//       while (left < right)
//       {
//         int sum = nums[left] + nums[right];
//         if (target == sum)
//         {
//           std::vector<int> temp = {nums[i], nums[left], nums[right]};
//           sort(temp.begin(),temp.end());
//           s.insert(temp);
//           left++;
//           right--;
//         }
//         else if(sum<target)
//         {
//           left++;
//         }
//         else{
//           right--;
//         }
//       }
//     }
//     for(auto it:s)
//     {
//       vec.push_back(it);
//     }
//     return vec;
//   }
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
  Solution sol;
  std::vector<std::vector<int>> ans = sol.threeSum(vec);
  for (int i = 0; i < ans.size(); i++)
  {
    for (auto it : ans[i])
    {
      std::cout << it << " ";
    }
    std::cout << "\n";
  }
}
