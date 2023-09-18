#include <bits/stdc++.h>
using namespace std;

//TC: O(n)
//SC: O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    unordered_map<int,int> freq;
    for(int i=0;i<nums.size();i++)
    {
        freq[nums[i]]++;
        if(freq[nums[i]]>nums.size()/3)
        {
            ans.push_back(nums[i]);
        }
    }
    unordered_set<int> ans_set(ans.begin(), ans.end());
    return vector<int>(ans_set.begin(), ans_set.end());
    }
};

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