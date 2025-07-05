#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum1(vector<int> &nums, int goal) // The idea is make a prefix sum array, it stores
    // the current sum and the number of times this sum has come, we always check if it is possible to make
    // the the required goal using the sum till now - sum from start till some point, let's say we need to make 2
    // the current sum is 3 for 1 0 1 0 1, then there is a value in hashmap 1,2. it shows that at some 
    // point from the start we got the number subtracting which we can get goal.
    {
        // TC:O(n), SC:O(n)
        unordered_map<int, int> prefixSumCount; // SC:O(n)
        prefixSumCount[0] = 1;

        int currentSum = 0;
        int count = 0;

        for (int num : nums) // TC:O(n)
        {
            currentSum += num;

            if (prefixSumCount.find(currentSum - goal) != prefixSumCount.end())
            {
                count += prefixSumCount[currentSum - goal];
            }

            prefixSumCount[currentSum]++;
        }

        return count;
    }

    int atMost(vector<int> &nums, int k)
    {
        // TC:O(2n), SC:O(1)
        if (k < 0)
        {
            return 0;
        }
        int left = 0, right = 0, sum = 0, count = 0;

        while (right < nums.size()) // TC:O(n)
        {
            sum += nums[right];

            while (sum > k) // TC:O(n)
            {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int> &nums, int goal) // With sliding window, we can find subarrays with sum
    // sum less than equal to goal, so we do that, and find out subarray with sum equal to goal-1, we subtract
    // which will give the total count, now to implement this make the window always have less than the required sum
    // and the subarray count will be the number of elements in the current subarray, which we keep compiling
    // to get the total count, this because for range 1,3 in array 1 0 1 0 1, the subarray is 0,1,0. Here 
    // the subarrays are 0, {1,0}, {0,1,0} ie. ending at end.
    {
        // TC:O(4n), SC:O(1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main()
{
    int n, goal;
    cin >> n >> goal;
    vector<int> nums(n);
    for (int &it : nums)
    {
        cin >> it;
    }
    Solution sol;
    int ans = sol.numSubarraysWithSum(nums, goal);
    cout << ans;
    return 0;
}