#include <bits/stdc++.h>

 using namespace std;

// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n=nums.size();
//         int cnt=0;
//         for(int i=1;i<n;i++){
//             if(nums[i-1]>nums[i]){
//                 cnt++;
//             }
//         }
//         if(nums[n-1]>nums[0]){
//             cnt++;
//         }// 
//         return cnt<=1; 
//     }
// };


// the second test is necessary for test case like [2,1,3,4,5]
class Solution {
public:
    bool check(vector<int>& nums) {
      vector<int> vec;
      vec=nums;
      sort(vec.begin(),vec.end());
      bool result=false;

      for(int i=0;i<nums.size();i++)
      {
        rotate(nums.begin(), nums.begin()+1, nums.end());
        if(nums==vec)
        {
         result=true;
        }
      }
      return result;
    }
};

// My:
// time complexity: O(n^2)
// Space complexity: O(n)

// Optimal:
// Time complexity:O(N)
// Space complexity:O(1)

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
    bool ans=sol.check(nums);
    cout<<ans;
}