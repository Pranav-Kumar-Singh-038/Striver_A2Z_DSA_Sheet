#include <bits/stdc++.h>
using namespace std;

//Optimal
//TC O(n), yeah nothing much
//SC O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)  // there can only be two such numbers, the first pass is used to find the potential candidates (two numbers which have the maximum freqs), then we count their freqs to verfy it then push
    {
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            else if(num2 == element){
                count2++;
            }
            else if(count1 == 0){
                num1 = element;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = element;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }////
      
      int countfin2=0;
      int countfin1=0;
      for(auto it:nums)
      {
        if(it==num1)
        {
            countfin1++;
        }
        if(it==num2)
        {
            countfin2++;
        }
      }
      vector<int> ans;
      if(countfin1>(nums.size()/3))
      {
        ans.push_back(num1);
      }
      if(countfin2>(nums.size()/3))
        {
       ans.push_back(num2);
        }
      return ans;
    }
};

//TC: O(n)
//SC: O(n)
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//     vector<int> ans;
//     unordered_map<int,int> freq;
//     for(int i=0;i<nums.size();i++)
//     {
//         freq[nums[i]]++;
//         if(freq[nums[i]]>nums.size()/3)
//         {
//             ans.push_back(nums[i]);
//         }
//     }
//     unordered_set<int> ans_set(ans.begin(), ans.end());
//     return vector<int>(ans_set.begin(), ans_set.end());
//     }
// };

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution sol;
    vector<int> ans=sol.majorityElement(nums);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
