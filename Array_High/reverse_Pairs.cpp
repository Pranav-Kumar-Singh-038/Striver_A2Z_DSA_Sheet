#include <iostream>
#include <vector>
#include <algorithm>

//Second Approach
//TC: O(nlogn)
//SC: O(n)
// Beats 95 and 89 percent respectively
class Solution {
public:
    int reversePairs(std::vector<int>& nums) {
        std::vector<int> sorted(nums.size());
        return mergeSortAndCount(nums, sorted, 0, nums.size() - 1);
    }

private:
    int mergeSortAndCount(std::vector<int>& nums, std::vector<int>& sorted, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, sorted, left, mid) + mergeSortAndCount(nums, sorted, mid + 1, right);

        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
            i++;
        }

        i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                sorted[k++] = nums[i++];
            } else {
                sorted[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            sorted[k++] = nums[i++];
        }

        while (j <= right) {
            sorted[k++] = nums[j++];
        }

        for (i = left; i <= right; i++) {
            nums[i] = sorted[i];
        }

        return count;
    }
};


// First Approach
// TC: O(n^2)
// SC: O(1)
//  class Solution
//  {
//  public:
//      int reversePairs(std::vector<int> &nums)
//      {
//          int count = 0;
//          for (int i = 0; i < nums.size() - 1; i++)
//          {
//              for (int j = i + 1; j < nums.size(); j++)
//              {
//                  long long int n=nums[j];
//                  long long int num=2*n;
//                  if (nums[i] > num)
//                  {
//                      count++;
//                  }
//              }
//          }
//          return count;
//      }
//  };

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums;
    while (n--)
    {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    Solution sol;
    int ans = sol.reversePairs(nums);
    std::cout << ans;
}