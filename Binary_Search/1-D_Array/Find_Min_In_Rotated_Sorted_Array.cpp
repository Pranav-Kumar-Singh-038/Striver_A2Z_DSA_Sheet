#include <iostream>
#include <vector>
#include <algorithm>

// Optimal 2- Striver
//  Complexity : same
class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int min = nums[0];
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[l])
            {
                if (min > nums[l])
                {
                    min = nums[l];
                }
                l = mid + 1;
            }
            else
            {
                if (min > nums[mid])
                {
                    min = nums[mid];
                }
                r = mid - 1;
            }
        }
        return min;
    }
};

// Optimal
// TC: same
// SC: same
// handles non- unique case too
// class Solution
// {
// public:
//     int findMin(std::vector<int> &nums)
//     {
//         int l = 0;
//         int r = nums.size()-1;
//         while (l <= r)
//         {
//             int mid = l + (r - l) / 2;
//             if (nums[mid] > nums[r])
//             {
//                 l = mid +1; // left side has small values (rotated array)
//             }
//             else if (nums[mid] < nums[r])
//             {
//                 r = mid;
//             } // right side has small value (not rotated)
//             else
//             {
//                 r--;
//             } // mid value equal to end move towards small
//         }
//         return nums[l];
//     }
// };

// My approach
//  TC: O(logn)
//  SC: O(1)
//  class Solution
//  {
//  public:
//      int findMin(std::vector<int> &nums)
//      {
//          int l = 0;
//          int r = nums.size() - 1;
//          int mid;
//          while (l <= r)
//          {
//              mid = l + (r - l) / 2;
//              if ((nums[mid] <= nums[(mid + 1) < (nums.size() - 1) ? mid + 1 : 0]) && (nums[mid] <= nums[(mid - 1) > (0) ? mid - 1 : nums.size() - 1]) && (nums[mid]<nums[l]) && (nums[mid]<nums[r]))
//              {
//                  return nums[mid];
//                  break;
//              }
//              if (nums[l] > nums[r])
//              {
//                  if (nums[mid] >= nums[l])
//                  {
//                      l = mid + 1;
//                  }
//                  else
//                  {
//                      r = mid - 1;
//                  }
//              }
//              else
//              {
//                  return nums[l];
//                  break;
//              }
//          }
//          return nums[mid];
//      }
//  };

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }
    Solution sol;
    int ans = sol.findMin(vec);
    std::cout << ans;
}