#include <bits/stdc++.h>
using namespace std;

class Solution
{ // Try to get the meetings which end early first then check the next meeting(greedy), for this sort the meetings based on their end times
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        // TC: O(2n +nlogn), SC: O(n)
        int n = start.size();
        if (n == 0)
            return 0;

        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++)
        {
            meetings.emplace_back(start[i], end[i]); //Both push_back() and emplace_back() add an element to the end of a vector, but emplace_back() is often faster because it constructs the element in-place, avoiding unnecessary copies or moves.
        }

        sort(meetings.begin(), meetings.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        int count = 1;
        int endTime = meetings[0].second;

        for (int i = 1; i < n; i++)
        {
            if (meetings[i].first > endTime)
            {
                count++;
                endTime = meetings[i].second;
            }
        }
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    for (int &x : start)
    {
        cin >> x;
    }
    for (int &x : end)
    {
        cin >> x;
    }
    Solution sol;
    int ans = sol.maxMeetings(start, end);
    cout << ans;
    return 0;
}