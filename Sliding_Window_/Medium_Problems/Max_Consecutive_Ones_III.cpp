#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k) // start the head and tail at the start, keep moving the tail
    // and counting zeroes, also the current maxConsecutive, if zeroCount exceeds k, then move the head until
    // the zerocount comes back to k, then continue as planned, 
    {
        // TC:O(2n) = O(n), SC:O(1)
        int head = 0, tail = 0;
        int n = nums.size();
        int zeroCount = 0;
        int count = 0;
        int maxOnes=0;
        while (tail != n) // TC: O(n)
        {
            int element = nums[tail];
            zeroCount += (element == 0) ? 1 : 0;
            while (zeroCount > k) // TC: O(n)
            {
                int headElement=nums[head];
                zeroCount-=(headElement==0)?1:0;
                head++;
            }
            count = tail - head + 1;
            maxOnes=max(maxOnes,count);
            tail++;
        }
        return maxOnes;
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
    int ans = sol.longestOnes(vec, k);
    cout << ans;
    return 0;
}