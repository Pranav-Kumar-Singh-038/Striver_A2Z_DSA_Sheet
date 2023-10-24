#include <iostream>
#include <vector>

//My appraoch
//TC: O(logn)
//SC: O(1)
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = l + (r - l) / 2;
        while (l<=r)
        {
            if (nums[mid] == target)
            {
                return mid;
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
        return -1;
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
    int ans = sol.search(nums, target);
    std::cout << ans;
}