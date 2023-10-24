#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
//Optimal: Cleaner code
//TC: O(n)
//SC: O(1)
// class Solution {
// public:
//     int maxSubArray(std::vector<int>& nums) {
//         int maxSum = nums[0];
//         int currentSum = nums[0];

//         for (int i = 1; i < nums.size(); i++) {
//             currentSum = std::max(nums[i], currentSum + nums[i]);
//             maxSum = std::max(maxSum, currentSum);
//         }

//         return maxSum;
//     }
// };

//MY
//TC : O(n)
//SC : O(1)
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int sum=0;
        int maxSum=nums[0];
        for(int i=0;i<nums.size();i++)
        {
         sum+=nums[i];
         if(sum>maxSum)
         {
          maxSum=sum;
         }
         if(sum<=0 ){
            sum=0;
         }
        }
        return maxSum;
    }
};

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> vec;
    for(int i=0;i<n;i++)
    {
        int x;
        std::cin>>x;
        vec.push_back(x);
    }
    Solution sol;
    int ans=sol.maxSubArray(vec);
    std::cout<<ans;
}