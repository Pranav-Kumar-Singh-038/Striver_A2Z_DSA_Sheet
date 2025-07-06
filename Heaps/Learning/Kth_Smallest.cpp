#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // a priority queue store largest element on top, so you insert it into that
    // and whenever size increases more than k, you pop, you ensure all larger element
    // are popped eventually leaving only k smaller ones, out of which the top ones is kth smallest
    // because it is largest in the k smallest ones.
    int kthSmallest(vector<int> &arr, int k)
    {
        // TC:O(2logk)=O(logk), SC:O(k)
        priority_queue<int> pq; // SC:O(k)
        for(int &it:arr) // TC:O(n)
        {
            pq.push(it); // TC:O(logk)
            if(pq.size()>k)
            {
                pq.pop(); // TC:O(logk)
            }
        }
        return pq.top();
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int &it : vec)
    {
        cin >> it;
    }

    Solution sol;
    int ans=sol.kthSmallest(vec,k);
    cout<<ans;
}