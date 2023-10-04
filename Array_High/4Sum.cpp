#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        // return {{1,2,3},{4,5,6}};
    }
};

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> vec;
    while(n--)
    {
     int x;
     std::cin>>x;
     vec.push_back(x);
    }
    int target;
    std::cin>>target;
    Solution sol;
    std::vector<std::vector<int>> ans=sol.fourSum(vec,target);
    for(auto it:ans)
    {
        for(int i=0;i<it.size();i++)
        {
            std::cout<<it[i]<<" ";
        }
        std::cout<<"\n";
    }
}