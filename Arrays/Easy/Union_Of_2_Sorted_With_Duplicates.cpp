#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) // skip all duplicates except the first, iterate both arrays, if find smaller insert into ans, if elements left in any array, manually add them while skipping duplicates
    {
        // TC: O(n+m), SC: O(n+m) (for answer)
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        int i = 0, j = 0;
        int highest = INT_MIN;
        while (i < n && j < m)
        {

            while (i < n && a[i] == a[i - 1])
            {
                i++;
            }
            while (j < m && b[j] == b[j - 1])
            {
                j++;
            }

            if (i == n || j == m)
            {
                break;
            }

            if (a[i] < b[j])
            {
                ans.push_back(a[i]);
                i++;
            }
            else if (a[i] > b[j])
            {
                ans.push_back(b[j]);
                j++;
            }
            else
            {
                ans.push_back(b[j]);
                i++;
                j++;
            }
        }
        while (i < n)
        {
            if (i == 0 || a[i] != a[i - 1])
            {
                ans.push_back(a[i]);
            }
            i++;
        }

        while (j < m)
        {
            if (j == 0 || b[j] != b[j - 1])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec1(n);
    vector<int> vec2(m);
    for (auto &it : vec1)
    {
        cin >> it;
    }
    for (auto &it : vec2)
    {
        cin >> it;
    }
    Solution sol;
    vector<int> ans = sol.findUnion(vec1, vec2);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}