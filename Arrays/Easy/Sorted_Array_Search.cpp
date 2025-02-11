#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) { // Binary search
        // TC: O(logn), SC: O(1)
      int low=0;
      int high=arr.size();
      int mid;
      while(low<=high)
      {
        mid=low+(high-low)/2;
        if(arr[mid]==k)
        {
            return true;
        }
        else if(arr[mid]<k)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
      }
      return false;
    }

};

int main(void) {
 int n,k;
 cin>>n>>k;
 vector<int> vec(n);
 for(int &x:vec)
 {
    cin>>x;
 }
 Solution sol;
 bool ans=sol.searchInSorted(vec,k);
 cout<<ans;
}

