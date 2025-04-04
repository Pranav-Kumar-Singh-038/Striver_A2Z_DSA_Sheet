#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k) // The core logic is that you need to make a sliding window which always has a valid freq array, a valid freq array fulfills the condition nums[r] * windowLength <= windowTotal + k, which is basically checking if the k we have is sufficient to make the frequency array, for that we sort it at the start so we can use sliding window
    {
        // TC: O(nlogn) +O(n) = O(nlogn), SC: O(1)
        int n = nums.size();
        if (nums.size() == 1)
        {
            return 1;
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int maxFreq = 1;
        long long windowTotal = nums[0];
        while (r < n)
        {
            int windowLength = r - l + 1;
            if ((long long)nums[r] * windowLength <= windowTotal + k)
            {
                maxFreq = max(maxFreq, windowLength);
                r++;
                if (r  < n)
                {
                    windowTotal += nums[r];
                }
            }
            else
            {
                windowTotal -= nums[l];
                l++;
            }
        }
        return maxFreq;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }

    Solution sol;
    int ans = sol.maxFrequency(vec, k);
    cout << ans;
    return 0;
}