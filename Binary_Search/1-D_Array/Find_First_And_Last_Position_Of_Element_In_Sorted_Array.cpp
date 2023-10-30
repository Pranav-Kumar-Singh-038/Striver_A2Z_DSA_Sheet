#include <iostream>
#include <vector>
#include <limits.h>
// My solution
// TC: O(n)
// SC: O(1)
class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = l + (r - l) / 2;
        int index;
        bool ans = false;
        while (l <= r)
        {
            if (nums[mid] == target)
            {
                index = mid;
                ans = true;
                break;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
                mid = l + (r - l) / 2;
            }
            else
            {
                l = mid + 1;
                mid = l + (r - l) / 2;
            }
        }
        if (!ans)
        {
            index = -1;
        }

        if (index == -1)
        {
            return {-1, -1};
        }
        else
        {
            int low = index;
            int high = index;
            while (nums[low] == target && low != 0)
            {
                low--;
                if (low == 0 && nums[0] == target)
                {
                    break;
                }
            }
            if (nums[low] != target)
            {
                low++;
            }
            while (nums[high] == target && high != nums.size() - 1)
            {
                high++;
                if (high == nums.size() - 1 && nums[nums.size() - 1] == target)
                {
                    break;
                }
            }
            if (nums[high] != target)
            {
                high--;
            }
            return {low, high};
        }
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    int target;
    std::cin >> target;
    Solution sol;
    std::vector<int> ans = sol.searchRange(nums, target);
    for (auto it : ans)
    {
        std::cout << it << " ";
    }
}