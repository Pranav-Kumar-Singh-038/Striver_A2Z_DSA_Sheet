#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    vector<int> findPeakGrid1(vector<vector<int>>& mat) { // Brute force
        // TC: O(m*n), SC: O(1)
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int curr = mat[i][j];

                int top = (i > 0) ? mat[i - 1][j] : -1;
                int bottom = (i < m - 1) ? mat[i + 1][j] : -1;
                int left = (j > 0) ? mat[i][j - 1] : -1;
                int right = (j < n - 1) ? mat[i][j + 1] : -1;

                if (curr > top && curr > bottom && curr > left && curr > right) {
                    return {i, j};
                }
            }
        }

        return {-1, -1}; // Unreachable as all elements are unique so one will be max
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) { //binary search on rows, selecting the middle row, finding the maximum element in that row, and then comparing it with its top and bottom neighbors to determine if it's a peak or if the search should continue in the upper or lower half of the matrix.
        // TC: O(mlogn), SC: O(1)
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int r=n-1;
        int mid;
        while(l<=r) // TC: O(mlogn)
        {
            // finds the middle row
            mid=l+(r-l)/2;
             
            // find the max element in concerned row
            vector<int> &vec=mat[mid]; // SC: O(1)
            int maxindex=0;
            int max=vec[0];
            int element;
            for(int i=1;i<m;i++) // TC: O(m)
            {
                 element=vec[i];
                 if(element>max)
                 {
                    max=element;
                    maxindex=i;
                 }
            }

            // if max element of row is greater than top and bottom elements return the indices, else if top is greater move there else move botttom, if both are greater move to top part does'nt matter
            int top=mid-1>=0?mat[mid-1][maxindex]:-1;
            int bottom=mid+1<n?mat[mid+1][maxindex]:-1;
            if(max>top && max>bottom)
            {
                return {mid,maxindex};
            }
            else if(top>max)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
         // In theory, this shouldn't be reached
        return {-1, -1};  
        }
    }
};

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> matrix(n,vector<int>(m));
  for(auto &row:matrix)
  {
    for(int &element:row)
    {
        cin>>element;
    }
  }
  Solution sol;
  vector<int> ans=sol.findPeakGrid(matrix);
  cout<<ans[0]<<" "<<ans[1];
  return 0;
}