#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void selectionSort(vector<int> &arr) { // Find the smallest replace with 1st index, find the second smallest replace with 2nd index
        // TC: O(n^2), SC: O(1)
        for(int i=0;i<arr.size();i++)
          {
            int smallest=i;
            for(int j=i+1;j<arr.size();j++)
            {
              if(arr[j]<arr[smallest])
              {
                smallest=j;
              }
            }
            swap(arr[i], arr[smallest]);
          }

          for(auto it:arr)
          {
            cout<<it<<" ";
          }
      }
 
    };

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int &x:vec)
    {
        cin>>x;
    }

    Solution sol;
    sol.selectionSort(vec);
    return 0;
}