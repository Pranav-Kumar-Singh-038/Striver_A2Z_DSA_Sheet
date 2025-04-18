#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool searchMatrix1(vector<vector<int>>& matrix, int target) { // Brute force
        // TC:O(n*m), SC: O(1)
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == target) return true;
            }
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) { // Binary search on each row
        // TC: O(mlogn), SC: O(1)
        int m = matrix.size();
        int n = matrix[0].size();
    
        for (int i = 0; i < m; i++) {
            int low = 0, high = n - 1;
    
            while (low <= high) {
                int mid = low + (high - low) / 2;
    
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }
    

    bool searchMatrix(vector<vector<int>>& matrix, int target) { // Staircase approach, start from top right or bottom left, because there in the left all elements are smaller and below all elements are larger, so if your number is less than it isn't in the row so move down eliminating the row, similarly if larger move left as all elements in that column are larger, eliminating the column.
        // TC: O(m+n), SC: O(1)
          int m=matrix.size();
          int n=matrix[0].size(); 
          int row=0;
          int column=n-1;
          while(row<=m-1 && column>=0)
          {
            int element=matrix[row][column];
            if(element==target)
            {
                return 1;
            }
            else if(element<target)
            {
                row++;
            }
            else
            {
                column--;
            }
          } 
          return 0;
    }
};

int main()
{
  int n,m,target;
  cin>>n>>m>>target;
  vector<vector<int>> matrix(n,vector<int>(m));
  for(auto &row:matrix)
  {
    for(int &element:row)
    {
        cin>>element;
    }
  }
  Solution sol;
  bool ans=sol.searchMatrix(matrix,target);
  cout<<ans;
  return 0;
}