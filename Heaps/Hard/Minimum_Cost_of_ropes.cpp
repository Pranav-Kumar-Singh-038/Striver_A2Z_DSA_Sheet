#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        // simply push the array in a minheap, keep adding the top elements
        // this ensures you are adding the minimum cost, until 1 element is left,
        // this is the final length of the rope, keep adding cost in the meantime
        // TC:O(4nlogn)=O(nlogn), SC:O(n)
        priority_queue<int,vector<int>,greater<int>> minHeap; // SC:O(n)
        int cost=0; 
        for(int &it:arr) // TC:O(n)
        {
          minHeap.push(it); // TC:O(logn)
        }
        while(minHeap.size()>1) // TC:O(n)
        {
            int a=minHeap.top();
            minHeap.pop(); // TC:O(logn)
            int b=minHeap.top();
            minHeap.pop(); // TC:O(logn)
            cost+=a+b;
            minHeap.push(a+b); // TC:O(logn)
        }
        return cost;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &it:arr)
    {
        cin>>it;
    }
    Solution sol;
    int ans=sol.minCost(arr);
    cout<<ans;
}