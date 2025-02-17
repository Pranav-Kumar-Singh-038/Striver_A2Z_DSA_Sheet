#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> frequencyCount(vector<int> &arr) // using vector
    {
        // TC: O(2n), SC: O(1) not considering the ans vector
        int n=arr.size();
        vector<int> ans(n+1,0);
        for(auto it:arr)
        {
            ans[it]++;
        }
        ans.erase(ans.begin());
        return ans;
    }

    vector<int> frequencyCount2(vector<int> &arr) // using map
    {
        // TC: O(nlogn), SC: O(n)
        map<int, int> myMap;
        for (int i = 0; i < arr.size(); i++)
        {
            myMap[arr[i]]++;
        }

        vector<int> ans;
        for (int i = 1; i <= arr.size(); i++)
        {
            ans.push_back(myMap[i] ? myMap[i] : 0);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &x : vec)
    {
        cin >> x;
    }

    Solution sol;
    vector<int> ans = sol.frequencyCount(vec);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}