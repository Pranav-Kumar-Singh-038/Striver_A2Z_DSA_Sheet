#include <iostream>
#include <vector>

// Optimal
//  TC: O(logn)
// SC: O(1)
 class Solution {
 public:
     int search(std::vector<int>& nums, int target) {
         int left = 0;
         int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                // Left subarray is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // Right subarray is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

// Second Approach
// TC: O(n) if array is sorted
// Runtime: 3ms Beats 64%
// SC:O(1)
// Memory: 11.62 mb beats 12%

// int binarySearch(std::vector<int> nums, int target, int start,int end)
// {
//   int l = start;
//   int r = end;
//   int mid = l + (r - l) / 2;
//   while (l <= r)
//   {
//     if (nums[mid] == target)
//     {
//       return mid;
//     }
//     else if (nums[mid] > target)
//     {
//       r = mid - 1;
//       mid = l + (r - l) / 2;
//     }
//     else
//     {
//       l = mid + 1;
//       mid = l + (r - l) / 2;
//     }
//   }
//   return -1;
// }

// class Solution
// {
// public:
//   int search(std::vector<int> &nums, int target)
//   {
//     int index=0;
//     bool flag = true;

//     if(nums.size()==1)
//     {
//       if(nums[0]==target)
//       {
//         return 0;
//       }
//       else{
//         return -1;
//       }
//     }

//     for (int i = 1; i < nums.size(); i++)
//     {
//       if (nums[i - 1] > nums[i])
//       {
//         index = i;
//         flag = false;
//         break;
//       }
//     }
//     if (flag)
//     {
//       return binarySearch(nums,target,0,nums.size()-1);
//     }
//     else
//     {
//         int ans1=binarySearch(nums,target,0,index);

//         int ans2=binarySearch(nums,target,index,nums.size()-1);
//         // std::cout<<ans1<<" "<<ans2<<std::endl;
//         if (ans1 == -1 && ans2 == -1)
//         {
//           return -1;
//         }
//         else if (ans1 == -1)
//         {
//           return ans2;
//         }
//         else
//         {
//           return ans1;
//         }

//     }
//   }
// };

// First Approach
// Brute force
// TC: O(n)
// SC: O(1)
//  class Solution
//  {
//  public:
//      int search(std::vector<int> &nums, int target)
//      {
//        for(int i=0;i<nums.size();i++)
//        {
//          if(nums[i]==target)
//          {
//            return i;
//          }
//        }
//        return -1;
//      }
//  };

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
  int ans = sol.search(vec, target);
  std::cout << ans;
}