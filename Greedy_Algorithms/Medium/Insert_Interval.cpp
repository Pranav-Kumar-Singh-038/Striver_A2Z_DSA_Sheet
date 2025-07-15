#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // at start we push all intervals whose upper level is less than our lower one,
        // then for all the ranges whose lower levels are smaller than our upper one
        // we get the minimum of their lower and our lower, and max of their upper and
        // our upper, this gets the lowest range , lower than our lower range, and highest
        // range higher than upper range. we push it, then we insert reset of the vector 
        // go via tc 2 if doubt. 
        // TC:O(n), SC:O(n)
        vector<vector<int>> result; // SC:O(n)
        int i = 0;
        int n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0]) // TC:O(n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]) // TC:O(n)
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while (i < n) // TC:O(n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (vector<int> &interval : intervals)
    {
        cin >> interval[0];
        cin >> interval[1];
    }
    vector<int> newInterval(2);
    cin >> newInterval[0];
    cin >> newInterval[1];
    Solution sol;
    vector<vector<int>> ans = sol.insert(intervals, newInterval);
    for (vector<int> &interval : ans)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
}
