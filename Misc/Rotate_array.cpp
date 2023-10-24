#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> numcopy = nums;
//         for(int i=0;i<nums.size();i++) 
//             nums[(i+k)%nums.size()]=numcopy[i];
//     }
// };
//Time complexity: O(n)
//Space complexit: O(n)
//but this intuition is better

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()>=k)
        {
        std::rotate(nums.begin(), nums.begin()+nums.size()-k, nums.end());
        }
        else
        {
            while(k>nums.size())
            {
             k=k-nums.size();
            }
            std::rotate(nums.begin(), nums.begin()+nums.size()-k, nums.end());
        }
        for(int i=0;i<nums.size();i++)
         {
          cout<<nums[i]<<" ";
         }
    }
};
//my approach is optimal
//Time complexity: O(n)
//Space complexit: O(1)



int main()
{
    int n;
    cin>>n;

    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int k;
    cin>>k;
    Solution sol;
    sol.rotate(vec,k);
}