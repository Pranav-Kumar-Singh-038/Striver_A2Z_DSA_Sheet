#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printHeap(priority_queue<int,vector<int>, greater<int>> pq)
    {
        while(!pq.empty())
        {
            cout<<pq.top()<<" ";
            pq.pop();
        }
    }

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        // TC:O(nlogn+nlogn+n)=O(nlogn), SC:O(3n)= O(n)
        priority_queue<int,vector<int>, greater<int>> pq; // SC:O(n)
        unordered_map<int,int> hashMap; // SC:O(n)
        vector<int> ans(N); // SC:O(n)
        for(int &it:arr)// TC:O(n)
        {
           pq.push(it); // TC:O(logn)
        }
        int i=1;
        while(!pq.empty()) // TC:O(n)
        {
           if(hashMap.find(pq.top())==hashMap.end()) // TC:O(1) (O(n) in worst case)
           {
           hashMap[pq.top()]=i;
           i++;
           }
           pq.pop(); // TC:O(logn)
        }
        for(int i=0;i<N;i++) // TC:O(n)
        {
           ans[i]=hashMap[arr[i]];
        }
        return ans;
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
   vector<int> ans=sol.replaceWithRank(arr,n);
   for(int &it:ans)
   {
    cout<<it<<" ";
   }
}