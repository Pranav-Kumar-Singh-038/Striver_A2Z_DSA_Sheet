#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // We add the array in a min heap,
    // and pop the root whenever the priority queue exceeds k, what this does is
    //  it will always keep popping smallest values, and at end it will have popped
    //  all values after k largest(since pq is of size k).
    int findKthLargest(vector<int> &nums, int k)
    {
        // TC:O(2nlogk) = O(nlogk), SC:O(k)
        priority_queue<int, vector<int>, greater<int>> pq; // SC:O(k)
        for (int &it : nums)                               // TC:O(n)
        {
            pq.push(it); // TC:O(logk)
            if (pq.size() > k)
            {
                pq.pop(); // TC:O(log(k))
            }
        }
        return pq.top();
    }

    int findKthLargest1(vector<int> &nums, int k)
    {
        // TC:O(nlogn+klogn), SC:O(n)
        priority_queue<int> pq; // SC:O(n)
        for (int &it : nums)    // TC:O(nlogn)
        {
            pq.push(it);
        }
        while (k > 1) // TC:O(k)
        {
            pq.pop(); // TC:O(logn)
            k--;
        }
        return pq.top();
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &it : nums)
    {
        cin >> it;
    }

    Solution sol;
    int ans = sol.findKthLargest(nums, k);
    cout << ans;
    return 0;
}