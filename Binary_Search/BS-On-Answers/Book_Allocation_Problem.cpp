#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canAllocate(vector<int>& arr, int k, int limit) {
            // TC: O(n), SC :O(1)
            int count = 1;  
            int pages = 0;
    
            for (int i = 0; i < arr.size(); ++i) {
                if (arr[i] > limit) return false;  
                if (pages + arr[i] > limit) {
                    count++;      
                    pages = arr[i]; 
                } else {
                    pages += arr[i];
                }
            }
    
            return count <= k;
        }

        int findPages(vector<int>& arr, int k) { //Minimize the maximum pages any student gets by binary searching between the largest book and total pages, ensuring allocation to at most k students — return -1 if books are fewer than students.
            // TC: O(nlog(accumulate(arr)-max_element(arr))), SC: O(1)
            if (arr.size() < k) {
                return -1;
            }
    
            int low = *max_element(arr.begin(), arr.end()); // TC: O(n)
            int high = accumulate(arr.begin(), arr.end(), 0); // TC: O(n)
            int ans = -1;
    
            while (low <= high) { // TC: O(nlog(accumulate(arr)-max_element(arr)))
                int mid = low + (high - low) / 2;
    
                if (canAllocate(arr, k, mid))  // O(n)
                {
                    ans = mid;
                    high = mid - 1;  
                } 
                else 
                {
                    low = mid + 1;  
                }
            }
    
            return ans;
        }
};

int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> arr(n);
  for(int &element:arr)
  {
    cin>>element;
  }
  Solution sol;
  int ans=sol.findPages(arr,k);
  cout<<ans;
  return 0;
}