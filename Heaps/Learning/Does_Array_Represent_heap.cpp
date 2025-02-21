#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isMaxHeap(int arr[], int n) // In a heap for any element its left(2*i+1) and right(2*i+2) child are smaller or equal to it
    { 
        // TC: O(n), SC: O(1)
        for(int i=0;i<n;i++)
        {
            int element=arr[i];
            int left=2*i+1;
            int right= 2*i+2;
            if((left<n && arr[left]>element ) ||(  right<n && arr[right]>element))
            {
                return 0;
            }
        }
        return 1;
    }

};

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Solution sol;
    int ans=sol.isMaxHeap(arr,n);
    cout<<ans;
    return 0;
}