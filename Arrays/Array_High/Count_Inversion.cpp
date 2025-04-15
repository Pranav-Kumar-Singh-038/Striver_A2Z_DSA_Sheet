#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
      long long merge(vector<int> &arr, int l, int mid, int r) {
        
          vector<int> ans;
          int i = l, j = mid + 1;
          long long invCount = 0;
  
          while (i <= mid && j <= r) {
              if (arr[i] <= arr[j]) {
                  ans.push_back(arr[i]);
                  i++;
              } else {
                  ans.push_back(arr[j]);
                  j++;
                  invCount += (mid - i + 1);  // Count all remaining elements in left half
              }
          }
  
          while (i <= mid) {
              ans.push_back(arr[i++]);
          }
  
          while (j <= r) {
              ans.push_back(arr[j++]);
          }
  
          for (int k = l; k <= r; k++) {
              arr[k] = ans[k - l];
          }
  
          return invCount;
      }
  
      long long mergeSort(vector<int> &arr, int l, int r) {
          long long invCount = 0;
          if (l < r) {
              int mid = l + (r - l) / 2;
              invCount += mergeSort(arr, l, mid);
              invCount += mergeSort(arr, mid + 1, r);
              invCount += merge(arr, l, mid, r);
          }
          return invCount;
      }
  
      long long inversionCount(vector<int> &arr) { // // We use merge sort to recursively split the array and count inversions while merging, where an inversion is when a larger element appears before a smaller one. During merge, each time an element from the right half is placed before an element from the left, it contributes to the inversion count by the number of remaining elements in the left half.
        // TC: O(nlogn) SC: O(n)  
        return mergeSort(arr, 0, arr.size() - 1);
      }
};

int main()
{
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int &element:nums)
  {
    cin>>element;
  }

  Solution sol;
  int ans=sol.inversionCount(nums);
  cout<<ans;
  return 0;
}