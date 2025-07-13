#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        // The idea is to sort the arrival and departure arrays independently,
        // and then use two pointers i and j to simulate the train schedule in order.
        // If a train arrives before the earliest current departure (arr[i] <= dep[j]),
        // it means a new platform is needed, so we increment the platform count.
        // Otherwise, a train has departed, so we free up a platform.
        // We keep track of the maximum number of platforms needed at any point,
        // which is our final answer. The loop continues until all arrivals are processed.
        // optimal
        // TC:O(2nlogn) =O(nlogn), SC:O(1)
        sort(arr.begin(), arr.end()); // TC:O(nlogn)
        sort(dep.begin(), dep.end()); // TC:O(nlogn)
        int i = 0, j = 0;
        int n = arr.size();
        int platforms = 0, maxPlatforms = 0;
        while (i < n && j < n) // TC:O(n)
        {
            if (arr[i] <= dep[j])
            {
                platforms++;
                i++;
            }
            else
            {
                platforms--;
                j++;
            }
            maxPlatforms = max(platforms, maxPlatforms);
        }
        return maxPlatforms;
    }

    int findPlatform1(vector<int> &arr, vector<int> &dep)
    {
        // Sub optimal
        // add the arrivals and departures time in unordered_multimaps, then loop from
        // the first train arrival to last train departure, for each time, check which trains arrived
        // count them, record the maximum trains recorded ever, delete the departure times
        // we don't remove the departure trains because, it is given in question that
        // "At any given time, the same platform cannot be used for both the arrival of one train and the departure of another."
        // Time Complexity: O(4n+4Rk)=O(n + Rk), where
        //   n = number of trains
        //   R = endTime - startTime + 1
        //   k = average number of trains arriving/departing at any given time
        // Space Complexity: O(2n)=O(n)
        int count = 0;
        int maxCount = 0;
        unordered_multimap<int, int> arrMap;                  // SC:O(n)
        unordered_multimap<int, int> depMap;                  // SC:O(n)
        int startTime = *min_element(arr.begin(), arr.end()); // TC:O(n)
        int endTime = *max_element(dep.begin(), dep.end());   // TC:O(n)
        for (int &i : arr)                                    // TC:O(n)
        {
            arrMap.insert({i, 1}); // TC:O(1)
        }
        for (int &i : dep) // TC:O(n)
        {
            depMap.insert({i, 1}); // TC:O(1)
        }
        for (int t = startTime; t <= endTime; t++) // TC:O(R)
        {
            auto rangeA = arrMap.equal_range(t);                    // TC:O(k)
            for (auto it = rangeA.first; it != rangeA.second; ++it) // TC:O(k)
            {
                count++;
            }

            maxCount = max(maxCount, count);

            auto rangeD = depMap.equal_range(t);                    // TC:O(k)
            for (auto it = rangeD.first; it != rangeD.second; ++it) // TC:O(k)
            {
                count--;
            }
        }
        return maxCount;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), dep(n);
    for (int &it : arr)
    {
        cin >> it;
    }
    for (int &it : dep)
    {
        cin >> it;
    }
    Solution sol;
    int ans = sol.findPlatform(arr, dep);
    cout << ans;
}