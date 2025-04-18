#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {  // First the reqRow using binary search, then in that row find if the element is present using binary search
            // TC: O(logm+logn) = O(log(n*m)), SC: O(1)
            int n=matrix.size();
            int m=matrix[0].size();
            int L=0;
            int R=n-1;
            int MID,reqROW=0;
            while(L<=R) // TC: O(logn)
            {
                MID=L+(R-L)/2;
                if(matrix[MID][0]<=target)
                {
                    reqROW=MID;
                    L=MID+1;
                }
                else
                {
                  R=MID-1;
                }
            }
            vector<int> &vec=matrix[reqROW]; // SC: O(1)
            int l=0;
            int r=m-1;
            int mid,ans=-1;
            while(l<=r) // TC: O(logm)
            {
                mid=l+(r-l)/2;
                if(vec[mid]<=target)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            if(vec[ans]==target)
            {
                return true;
            }
            return false;
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

