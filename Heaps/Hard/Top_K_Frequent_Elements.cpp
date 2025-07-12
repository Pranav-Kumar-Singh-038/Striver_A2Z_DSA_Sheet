#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // TC:O(n+mlogk+mlogk+klogk) = O(mlogk)(worst case), SC:O(2m+k) = O(m)
        unordered_map<int, int> freq;           // SC:O(m), where m is the distinct elements in nums
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap; // SC:O(m)
        vector<int> ans(k);                     // SC:O(k)
        for (int &it : nums)                    // TC:O(n)
        {
            freq[it]++;
        }
        for (auto &[num, count] : freq) // TC:O(m)
        {
            minHeap.push({count, num}); // TC:O(logk)
            if(minHeap.size()>k)
            {
                minHeap.pop(); // logk
            }
        }
        for (int &it : ans) // TC:O(k)
        {
            it = minHeap.top().second;
            minHeap.pop(); // TC:O(logk)
        }
        return ans;
    }

    vector<int> topKFrequent1(vector<int> &nums, int k)
    {
        // make a frequency array, push it into a max heap, the answer is the top k elments of maxheap
        // Suboptimal
        // TC:O(n+mlogm+klogm), SC:O(2m+k)
        unordered_map<int, int> freq;           // SC:O(m), where m is the distinct elements in nums
        priority_queue<pair<int, int>> maxHeap; // SC:O(m)
        vector<int> ans(k);                     // SC:O(k)
        for (int &it : nums)                    // TC:O(n)
        {
            freq[it]++;
        }
        for (auto &[num, count] : freq) // TC:O(m)
        {
            maxHeap.push({count, num}); // TC:O(logm)
        }
        for (int &it : ans) // TC:O(k)
        {
            it = maxHeap.top().second;
            maxHeap.pop(); // TC:O(logm)
        }
        return ans;
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
    vector<int> ans = sol.topKFrequent(nums, k);
    for (int &it : ans)
    {
        cout << it << " ";
    }
}