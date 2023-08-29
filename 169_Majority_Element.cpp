#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
//Optimal: Moore Voting Algorithm
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};

//better: hash map to store the frequency of each element and return the element with frequency more than n/2
//TC: O(n)
//SC: O(n)
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> m;
        
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        n = n/2;
        for(auto x: m){
            if(x.second > n){
                return x.first;
            }
        }
        return 0;
    }
};

//Given : if an element is majority after it is sorted it will occupy n/2 index
//TC O(nlogn)
//SC O(1)
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};

//TC O(nlogn)
//SC O(1)
class Solution {
public:
    int majorityElement(std::vector<int>& nums) 
    {
        std::sort(nums.begin(),nums.end());
        int count=1;
        int maxCount=1;
        int index;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                count++;
            }
            else{
                count=1;
            }
            if(count>maxCount)
            {
                maxCount=count;
                index=i;
            }
        }
        return nums[index];
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
  int ans=sol.majorityElement(nums);
  std::cout<<ans;
}