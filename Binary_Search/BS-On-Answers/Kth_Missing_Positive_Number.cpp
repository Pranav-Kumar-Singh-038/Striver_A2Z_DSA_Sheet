#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositiveOptimal(vector<int> &arr, int k)
    {
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left + k;
    }

    int findKthPositive(vector<int> &arr, int k)
    {
        int ans;
        int natural = 1;
        int i = 0;
        while (i < arr.size())
        {
            if (arr[i] == natural)
            {
                i++;
                natural++;
                continue;
            }
            else if (arr[i] != natural)
            {
                int diff = arr[i] - natural;
                if (diff < k)
                {
                    natural = arr[i];
                    natural++;
                    i++;
                    k -= diff;
                }
                else
                {
                    ans = natural + k - 1;
                    return ans;
                }
            }
        }
        return natural + k - 1;
    }
};

int main()
{
    int n;
    int k;
    vector<int> nums;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution sol;
    int ans = sol.findKthPositive(nums, k);
    cout << ans << endl;
}