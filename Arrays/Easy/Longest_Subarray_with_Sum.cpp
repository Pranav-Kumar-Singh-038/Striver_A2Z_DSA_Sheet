#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k) // The key logic is to use prefix sum to get all sum from 0 to that index, but this does'nt cover all cases so we create a hashmap which then stores the first occurrence of the prefixsum (this is done as the answer is the subarray after the prefixsum of (currentsum -k) was found) then we simply check if it is k or not and return the longest subarray , the only difference if the array is all positive is that this becomes a sliding window question
    {
        // SC: O(n), TC: O(n)
        int prefixSum = 0;
        unordered_map<int, int> prefixMap; // SC: O(n)
        int longest = 0;
        for (int i = 0; i < arr.size(); i++) // TC: O(n)
        {
            prefixSum += arr[i];
            if(prefixMap.find(prefixSum)==prefixMap.end()) // TC: O(1) average case
            {
                prefixMap[prefixSum] = i;
            }
            if (prefixSum == k)
            {
                longest = max(longest, i + 1);
            }
            if (prefixMap.find(prefixSum - k)!=prefixMap.end())  // TC: O(1) average case
            {
                longest = max(longest, i - prefixMap[prefixSum - k] );
            }
        }
        return longest;
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
    int ans = sol.longestSubarray(vec, k);
    cout << ans;
    return 0;
}