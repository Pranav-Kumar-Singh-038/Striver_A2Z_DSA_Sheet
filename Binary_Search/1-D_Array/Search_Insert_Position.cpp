#include <iostream>
#include <vector>

// My approach
//Optimal
//TC:O(log n)
//SC:O(1)
class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = l + (r - l) / 2;
        while (l <= r)
        {
            if (nums[mid] == target)
            {
                return mid;
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
        return mid;
    }
};

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> nums;
    while(n--)
    {
        int x;
        std::cin>>x;
        nums.push_back(x);
    }
    int target;
    std::cin>>target;
    Solution sol;
    int ans=sol.searchInsert(nums,target);
    std::cout<<ans;
}