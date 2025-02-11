#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countFreq(vector<int> &arr, int target) // calculate upper and lower bound and return diff-1 which is the range
    {
        // TC: O(2log(n)), SC: O(1)
        if (target > arr[arr.size() - 1] || target < arr[0])
        {
            return 0;
        }
        int low = 0;
        int high = arr.size() - 1;
        int mid;
        // for lower bound
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] >= target)
            {
                high = mid - 1;
            }
            else if (arr[mid] < target)
            {
                low = mid + 1;
            }
        }
        int lowerBound = high;

        low = 0;
        high = arr.size() - 1;
        // for Upper bound
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else if (arr[mid] <= target)
            {
                low = mid + 1;
            }
        }
        int upperBound = low;

        int range = upperBound - lowerBound - 1;
        return range;
    }
};

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> vec(n);
    for (int &x : vec)
    {
        cin >> x;
    }

    Solution sol;
    int ans = sol.countFreq(vec, target);
    cout << ans;
}