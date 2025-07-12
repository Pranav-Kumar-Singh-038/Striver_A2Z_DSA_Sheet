#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // the idea is, we keep track of the maximum possible reach currently
        // but instead of updating maxReach whenever a greater reach is found, which 
        // causes redundant jumps , we only jump when we cross the last maxReach, which is end
        // which was updated when we last jumped, that means for a range, first we determin
        // upto where can we reach, reach there, than jump till maximum reach we found in the said range
        // TC:O(n), SC:O(1)
        int maxReach=0;
        int jump=0;
        int end=maxReach;
        for(int i=0;i<nums.size()-1;i++) // TC:O(n)
        {
            maxReach=max(maxReach,nums[i]+i);
            if(i==end)
            {
                jump++;
                end=maxReach;
            }
        }
        return jump;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int &it:nums)
    {
        cin>>it;
    }
    Solution sol;
    int ans=sol.jump(nums);
    cout<<ans;
}