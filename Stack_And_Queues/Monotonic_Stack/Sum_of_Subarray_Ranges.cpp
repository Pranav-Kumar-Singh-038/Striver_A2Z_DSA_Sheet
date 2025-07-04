#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> calcLeftMax(vector<int> &nums) 
    {
        vector<int> leftMax(nums.size() + 1); // SC: O(n)
        stack<pair<int, int>> stk; // SC: O(n)
        for (int i = 0; i < nums.size(); i++) // TC: O(n)
        {
            int element = nums[i];
            int count = 1;
            while (!stk.empty() && stk.top().first < element) // TC: O(n)
            {
                count += stk.top().second;
                stk.pop();
            }
            stk.push({element, count});
            leftMax[i] = count;
        }
        return leftMax;
    }

    vector<int> calcRightMax(vector<int> &nums)
    {
        vector<int> rightMax(nums.size() + 1); // SC: O(n)
        stack<pair<int, int>> stk; // SC: O(n) 
        for (int i = nums.size() - 1; i >= 0; i--) // TC: O(n)
        {
            int element = nums[i];
            int count = 1;
            while (!stk.empty() && stk.top().first <= element) // TC: O(n)
            {
                count += stk.top().second;
                stk.pop();
            }
            stk.push({element, count});
            rightMax[i] = count;
        }
        return rightMax;
    }

    vector<int> calcLeftMin(vector<int> &nums)
    {
        vector<int> leftMin(nums.size() + 1); // SC: O(n)
        stack<pair<int, int>> stk; // SC: O(n)
        for (int i = 0; i < nums.size(); i++) // TC: O(n)
        {
            int element = nums[i];
            int count = 1;
            while (!stk.empty() && stk.top().first > element) // TC: O(n)
            {
                count += stk.top().second;
                stk.pop();
            }
            stk.push({element, count});
            leftMin[i] = count;
        }
        return leftMin;
    }

    vector<int> calcRightMin(vector<int> &nums)
    {
        vector<int> rightMin(nums.size() + 1); // SC: O(n)
        stack<pair<int, int>> stk; // SC: O(n)
        for (int i = nums.size() - 1; i >= 0; i--) // TC: O(n)
        {
            int element = nums[i];
            int count = 1;
            while (!stk.empty() && stk.top().first >= element) // TC: O (n)
            {
                count += stk.top().second;
                stk.pop();
            }
            stk.push({element, count});
            rightMin[i] = count;
        }
        return rightMin;
    }

    vector<int> calcMax(vector<int> &nums)
    {
        vector<int> maxArray(nums.size() + 1); // SC: O(n)
        vector<int> leftMax = calcLeftMax(nums);   // SC: O(2n), TC: O(2n)
        vector<int> rightMax = calcRightMax(nums);  // SC: O(2n), TC: O(2n)
        for (int i = 0; i < nums.size(); i++) // TC: O(n)
        {
            maxArray[i] = leftMax[i] * rightMax[i];
        }
        return maxArray;
    }

    vector<int> calcMin(vector<int> &nums)
    {
        vector<int> minArray(nums.size() + 1); // SC: O(n)
        vector<int> leftMin = calcLeftMin(nums); // SC: O(2n), TC: O(2n)
        vector<int> rightMin = calcRightMin(nums); // SC: O(2n), TC: O(2n)
        for (int i = 0; i < nums.size(); i++) // TC: O(n)
        {
            minArray[i] = leftMin[i] * rightMin[i];
        }
        return minArray;
    }

    long long subArrayRanges(vector<int> &nums) // the logic is we need need range sum, a range is max(subarray) - min(subarray), and 
    // add it, since we are adding it, ie. 1-1 + 2-1 + 3-1 + 2-2 + 3-2 + 3-3, which is (1+2+3+2+3+3) - (1+1+1+2+2+3), which is ( sum of 
    //     nums[i]* number of time nums[i] came as max) - ( sum of nums[i]* number of time nums[i] came as min), so we find for each 
    //     element the number of times it came as max, and number of times it came as min, which can be a super set of Sum of subarray of 
    //     minimums
    {
        // TC: O(11n), SC: O(10n)
        vector<int> maxArray = calcMax(nums); //SC : O(5n) , TC: O(5n)  
        vector<int> minArray = calcMin(nums); // SC: O(5n) , TC: O(5n)
        long long total = 0;

        for (int i = 0; i < nums.size(); i++) // TC: O(n)
        {
            total += (long long)nums[i] * (maxArray[i] - minArray[i]);
        }

        return total;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &it : nums)
    {
        cin >> it;
    }
    Solution sol;
    long long ans = sol.subArrayRanges(nums);
    cout << ans;
    return 0;
}