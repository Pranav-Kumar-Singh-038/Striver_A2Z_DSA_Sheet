#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largest(vector<int> &arr) // Find largest
    {
        // TC: O(n), SC: O(1)
        int largest = arr[0];
        for (int x : arr)
        {
            if (x > largest)
            {
                largest = x;
            }
        }
        return largest;
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
    int ans = sol.largest(vec);
    cout << ans;
}
