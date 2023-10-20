#include <iostream>
#include <vector>
#include <algorithm>
//First Approach
//TC: O(n^2)
//SC: O(1)
class Solution
{
public:
    int reversePairs(std::vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                long long int n=nums[j];
                long long int num=2*n;
                if (nums[i] > num)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

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