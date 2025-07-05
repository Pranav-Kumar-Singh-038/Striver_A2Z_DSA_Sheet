#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // This function counts the number of subarrays with at most k odd numbers.
    // Think of it like the Binary Subarrays With Sum problem,
    // where odd = 1 and even = 0.
    // We maintain a window [head, tail] such that it has ≤ k odd numbers.
    // For each tail, all subarrays starting from head to tail are valid.
    // So we add (tail - head + 1) to the answer.
    // {1,1,2,1}, {1,2,1}, {2,1}, {1} 
    // we are counting subarrays who have at most k odd numbers
    int atMost(vector<int> &nums, int k)
    {
        // TC:O(2n), SC:O(1)
        int head = 0, tail = 0;
        int count = 0;
        int n = nums.size();
        int oddCount = 0;
        while (tail != n) // TC:O(n)
        {
            int element = nums[tail];
            oddCount += (element % 2 != 0) ? 1 : 0;
            while (oddCount > k) // TC:O(n)
            {
                int headElement = nums[head];
                oddCount -= (headElement % 2 != 0) ? 1 : 0;
                head++;
            }
            count += tail - head + 1;
            tail++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        // TC:O(4n), SC:O(1)
        int ans = atMost(nums, k) - atMost(nums, k - 1);
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &it : nums)
    {
        cin >> it;
    }
    Solution sol;
    int ans = sol.numberOfSubarrays(nums, k);
    cout << ans;
    return 0;
}