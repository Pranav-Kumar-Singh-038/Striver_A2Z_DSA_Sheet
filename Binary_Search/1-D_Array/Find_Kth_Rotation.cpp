#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findKRotation(vector<int> &arr) // find the smallest and return it's index, remember the loop condition low<high to avoid infinite loop,  and update high=mid as it can skip the smallest index
  {
    // TC: O(logn), SC: O(1)
    int low = 0, high = arr.size() - 1;

    if (arr[low] <= arr[high]) {
        return low;
    }

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid; 
        }
    }
    
    return low;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int &x : vec)
  {
    cin >> x;
  }
  Solution sol;
  int ans = sol.findKRotation(vec);
  cout << ans;
}