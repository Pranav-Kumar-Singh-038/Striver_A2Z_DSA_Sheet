#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        std::vector<std::vector<int>> vec;
        std::vector<long long int> copy(nums.begin(), nums.end());
        unsigned long long int sum = 0;
        if (nums.size() < 4)
        {
            return vec;
        }
        std::set<std::vector<int>> s;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                for (int k = j + 1; k < nums.size() - 1; k++)
                {
                    for (int l = k + 1; l < nums.size(); l++)
                    {
                        sum = copy[i] + copy[j] + copy[k] + copy[l];
                        if (sum == target)
                        {
                            std::vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        for (auto it : s)
        {
            std::vector<int> temp(it.begin(), it.end());
            vec.push_back(temp);
        }
        return vec;
    }
};

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
    std::vector<std::vector<int>> ans = sol.fourSum(vec, target);
    for (auto it : ans)
    {
        // sort(it.begin(),it.end());
        for (int i = 0; i < it.size(); i++)
        {
            std::cout << it[i] << " ";
        }
        std::cout << "\n";
    }
}