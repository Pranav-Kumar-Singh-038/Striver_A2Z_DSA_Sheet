#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int floor = -1, ceil = -1;
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x) {
            return {x, x};
        }
        else if (a[mid] < x) {
            floor = a[mid];
            l = mid + 1;
        } else {
            ceil = a[mid];
            r = mid - 1;
        }
    }
    return {floor, ceil};
}


int main()
{
  int n,k;
  cin>>n>>k;
  
  vector<int> nums(n);
  for(int &element:nums)
  {
    cin>>element;
  }

  pair<int,int> ans=getFloorAndCeil(nums,n,k);
  cout<<ans.first<<" "<<ans.second;
  return 0;
}