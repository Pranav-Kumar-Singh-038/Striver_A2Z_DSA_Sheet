#include <bits/stdc++.h>

using namespace std;
//had a hunch it would be solved by XOR
//Optimal
//Time complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
};
//Knew this approach
//Time complexity: O(n.log(n))
//Space Complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
//Knew this approach
//Time complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       unordered_map<int,int> a;
	   for(auto x: nums)
		   a[x]++;
	   for(auto z:a)
		   if(z.second==1)
			   return z.first;
	   return -1;
    }
};
//My
//Time complexity: O(n.log(n))
//Space Complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        set<int> s(nums.begin(),nums.end());
        for(int i:s)
        {
            sum=sum-(2*i);
        }
        return sum*(-1);
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
    int ans=sol.singleNumber(nums);
    cout<<ans;
}