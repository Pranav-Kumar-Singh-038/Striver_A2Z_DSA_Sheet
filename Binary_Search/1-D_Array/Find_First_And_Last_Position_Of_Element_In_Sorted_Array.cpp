#include <iostream>
#include <vector>
#include <limits.h>

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = l + (r - l) / 2;
        int min = INT_MAX;
        int max = -1;
        while (l <= r && nums.size()!=0)
        {
            if (nums[mid] == target)
            {
                if (min > mid)
                {
                    min = mid;
                }
                if (max < mid)
                {
                    max = mid;
                }
                nums[mid]=target-1;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
                mid = l + (r - l) / 2;
            }
            else
            {
                r = mid - 1;
                mid = l + (r - l) / 2;
            }
        }
        if (min == INT_MAX)
        {
            return {-1, -1};
        }
        else
        {
            return {min, max};
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