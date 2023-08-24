#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
//Optimal
//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
       int x=0;
       for(int l:nums){
           x^=l;
       }
       for(int i=0;i<=nums.size();i++){
           x^=i;
       }
       return x;
    }
};
//Mine
//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
    int sum=accumulate(nums.begin(),nums.end(),0);
    int acsum=(nums.size()*nums.size()+nums.size())/2;
    return acsum-sum;
    }
};

int main()
{
   int n;
   std::cin>>n;
   
   std::vector<int> nums;
   for(int i=0;i<n;i++)
   {
    int x;
    std::cin>>x;
    nums.push_back(x);
   }
    
   Solution sol; 
   int ans=sol.missingNumber(nums);
   std::cout<<ans;

}