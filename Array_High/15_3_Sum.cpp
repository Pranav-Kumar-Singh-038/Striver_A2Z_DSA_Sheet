#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

// First Approach-:
// TC : O(nlogn)
// SC : O(n)
class Solution
{
public:
  std::vector<std::vector<int>> majorityElement(std::vector<int> &nums)
  {
    std::vector<std::vector<int>> vec;
    std::set<std::vector<int>> s;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size()-1; i++)
    {
      int target = -nums[i];
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right)
      {
        int sum = nums[left] + nums[right];
        if (target == sum)
        {
          std::vector<int> temp = {nums[i], nums[left], nums[right]};
          sort(temp.begin(),temp.end());
          s.insert(temp);
          left++;
          right++;
        }
        else if(sum<target)
        {
          left++;
        }
        else{
          right--;
        }
      }
    }
    for(auto it:s)
    {
      vec.push_back(it);
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
  Solution sol;
  std::vector<std::vector<int>> ans = sol.majorityElement(vec);
  for (int i = 0; i < ans.size(); i++)
  {
    for (auto it : ans[i])
    {
      std::cout << it << " ";
    }
    std::cout << "\n";
  }
}
