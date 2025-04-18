#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) { // since the rows are sorted we can apply binary search in them to find the first 1 with which we can find the number of ones, this takes logm time, we do this for every row which makes it to be nlogm
    // TC: O(nlogm), SC: O(1)
    int maxOnes=0;
    int index=0;
    int maxIndex=-1;
    for(auto &row:matrix) // TC: O(nlogm)
    {
       int l=0;
       int r=m-1;
       int mid,ans=-1;
       while(l<=r) // TC: O(log(m))
       {
         mid=l+(r-l)/2;
         if(row[mid]==1)
         {
            ans=mid;
            r=mid-1;
         }
         else
         {
            l=mid+1;
         }
       }
       if(ans!=-1)
       {
        if(m-ans>maxOnes)
        {
            maxOnes=m-ans;
            maxIndex=index;
        }
       }
       index++;
    }
    return maxIndex;
}

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
  int ans=rowWithMax1s(matrix,n,m);
  cout<<ans;
  return 0;
}