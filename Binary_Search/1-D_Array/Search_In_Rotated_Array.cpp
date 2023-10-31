#include <iostream>
#include <vector>

//First Approach
//Brute force
//TC: O(n)
//SC: O(1)
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]==target)
        {
          return i;
        }
      }
      return -1;
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
    int ans = sol.search(vec, target);
    std::cout << ans;
}