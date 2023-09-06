#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
       
    }
};

int main()
{
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> vec;
    for(int i=0;i<n;i++)
    {
        std::vector<int> nums;
        for(int j=0;j<m;j++)
        {
         int x;
         std::cin>>x;
         nums.push_back(x);
        }
        vec.push_back(nums);
    }
    Solution sol;
    std::vector<int> ans=sol.spiralOrder(vec);
    for(auto it:ans)
        {
            std::cout<<it<<" ";
        }
        std::cout<<"\n";
}