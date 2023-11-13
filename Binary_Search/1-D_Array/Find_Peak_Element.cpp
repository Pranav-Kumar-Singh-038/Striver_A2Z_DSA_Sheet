#include <bits/stdc++.h>
using namespace std;
//Optimal approach(mine)
//Complexities O(logn) O(1)
// Beats 65% and 71% respectively
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
            {
                return mid;
            }
            else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }
};

// Brute force
// Complexities: O(n) and O(1) beats 32 and 97% respectively
//  class Solution
//  {
//  public:
//      int findPeakElement(vector<int> &nums)
//      {
//          if(nums.size()==1)
//          {
//              return 0;
//          }
//          if (nums[0] > nums[1])
//          {
//              return 0;
//          }
//          else if (nums[nums.size() - 1] > nums[nums.size() - 2])
//          {
//              return nums.size() - 1;
//          }
//          else
//          {
//              for (int i = 1; i < nums.size() - 1; i++)
//              {
//                 if(nums[i]>nums[i+1] && nums[i]>nums[i-1])
//                 {
//                  return i;
//                 }
//              }
//          }
//      }
//  };

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    Solution sol;
    int ans = sol.findPeakElement(vec);
    cout << ans;
}