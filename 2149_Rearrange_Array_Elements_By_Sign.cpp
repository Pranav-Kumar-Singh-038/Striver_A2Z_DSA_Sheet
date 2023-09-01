#include <iostream>
#include <vector>

//Optimal
//TC: O(n)
//SC: O(1)
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//        int n=nums.size();
//         vector<int>ans(n,0);
//         int posIndex=0;
//         int negIndex=1;
//         for(auto it:nums){
//             if(it>0){
//                 ans[posIndex]=it;
//                 posIndex+=2;
//             }
//             else{
//                  ans[negIndex]=it;
//                 negIndex+=2;
//             }
//         }
//         return ans;
//     }
// };


//My
//TC: O(n)
//SC: O(n)
class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) 
    {
        std::vector<int> pos;
        std::vector<int> neg;
        std::vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]<0)
          {
           neg.push_back(nums[i]);
          }
          else{
            pos.push_back(nums[i]);
          }
        }
        int j=0;
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
          if(i%2==0)
          {
            ans.push_back(pos[j]);
            j++;
          }
          else{
            ans.push_back(neg[k]);
            k++;
          }
        }
        return ans;
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
    std::vector<int> arr=sol.rearrangeArray(vec);
    for(int i:arr)
    {
        std::cout<<i<<" ";
    }
}