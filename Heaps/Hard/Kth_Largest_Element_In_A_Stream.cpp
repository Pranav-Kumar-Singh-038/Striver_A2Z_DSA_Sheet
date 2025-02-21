#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    int k;
    priority_queue<int,vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int> &nums) : k(k), minHeap(nums.begin(), nums.end())
    { // TC: O(nlogk)
        while (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    
    int add(int val)
    { // TC: O(logk)
        if (minHeap.size() < k || val > minHeap.top())
        {
            minHeap.push(val);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        return minHeap.top();
        
    }

};

class KthLargest1
{
public:
    int k;
    vector<int> nums;
    KthLargest1(int k, vector<int> &nums)
    { // TC:O(n)
        this->k = k;  
        this->nums = nums;
    }

    int add(int val)
    { // TC: O(nlogn)
        nums.push_back(val);
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

int main()
{
    int n,k,m;
    cin>>n>>m>>k;
    vector<int> vec(n);
    for(int &x:vec)
    {
        cin>>x;
    }
    vector<int> toAdd(m);
    for(int &x:toAdd)
    {
        cin>>x;
    }
    KthLargest* sol=new KthLargest(k,vec);
    for(int &i:toAdd)
    {
        cout<<sol->add(i)<<" ";
    }
    return 0;
}