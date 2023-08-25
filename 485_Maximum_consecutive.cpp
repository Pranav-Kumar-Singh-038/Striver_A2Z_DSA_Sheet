#include <bits/stdc++.h>
using namespace std;
//Optimal
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx = 0; // Maximum consecutive ones encountered
        int count = 0; // Current count of consecutive ones
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                if (count > maxx) {
                    maxx = count;
                }
            } else {
                count = 0; // Reset count for consecutive ones
            }
        }
        
        return maxx; // Return the maximum count
    }
};

//Mine
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int countprev = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            while (i < nums.size() && nums[i] == 1) {
                count++;
                i++;
            }
            
            if (count > countprev) {
                countprev = count;
            }
            
            count = 0;
        }
        
        return countprev;
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
    int ans=sol.findMaxConsecutiveOnes(nums);
    cout<<ans;
}