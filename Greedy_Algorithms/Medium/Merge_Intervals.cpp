#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // we take a vector merged, we sort the intervals vector, insert the shortest
        // lower interval to merged, start from 1, take prevInterval to be last of merged
        // currInterval to be current interval, if prevInterval's upper is greater than lower of
        // current interval(intersect), make the prevInterval's upper to be current's upper,
        // without inserting(this skips the redundant interval without erase command), then
        // keep repeating until the merged's upper is smaller than current's lower,(no intersection)
        // push into the merged vector, keep moving forward.
        // TC:O(nlogn+n)=O(nlogn), SC:O(n)
        vector<vector<int>> merged; // SC:O(n)
        sort(intervals.begin(), intervals.end()); // TC:O(nlogn)
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) // TC:O(n)
        {
            vector<int> &prevInterval = merged.back();
            vector<int> &currInterval = intervals[i];
            if (prevInterval[1] >= currInterval[0])
            {
               prevInterval[1]=max(prevInterval[1],currInterval[1]);
            }
            else
            {
                merged.push_back(currInterval);
            }
        }
        return merged;
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
    vector<vector<int>> ans = sol.merge(intervals);
    for (vector<int> &interval : ans)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
}