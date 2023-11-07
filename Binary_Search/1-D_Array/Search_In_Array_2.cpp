#include <iostream>
#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        bool ans=false;
        while(l<=r)
        {
          int mid=l+(r-l)/2;
          if(nums[mid]==target)
          {
            ans=true;
            break;
          }
          else if(nums[l]<=nums[mid])
          {
            if(nums[l]<=target && nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
          }
          else
          {
            if(nums[mid]<target && nums[r]>=target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
          }
          std::cout<<mid<<std::endl;
        }
        return ans;
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
bool ans=sol.search(nums,target);
if(ans)
{
    std::cout<<"true";
}
else
{
    std::cout<<"false";
}
}