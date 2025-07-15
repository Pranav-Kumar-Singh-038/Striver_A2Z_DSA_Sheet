#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // Again we sort by end times. Why? Because regardless of when a meeting
        // starts, a meeting that ends first leaves more time for other meetings to
        //  take place. We do not want a meeting that starts early and ends late,
        //  what we really care about is when the meeting ends and how much time it
        //   leaves for the other meetings. So, sort by endtimes, remove all
        //   overlapping meetings to get maximum meetings or reject minimum meetings
        // now sort with end times, start with second interval, if it overlaps with previous
        // count it, else make it the previous interval.
        // TC:O(n+nlogn)=O(nlogn), SC:O(1)
        int count = 0;
        sort(intervals.begin(), intervals.end(), compare); // TC:O(nlogn)
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) // TC:O(n)
        {
            if (intervals[i][0] < prevEnd)
            {
                count++;
            }
            else
            {
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (vector<int> &interval : intervals)
    {
        cin >> interval[0] >> interval[1];
    }
    Solution sol;
    int ans = sol.eraseOverlapIntervals(intervals);
    cout << ans;
    return 0;
}