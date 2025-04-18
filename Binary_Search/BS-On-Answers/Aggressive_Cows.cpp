#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int calcCowsFit(vector<int> &stalls,int minDistance) // always check the distance from the last placed cow, if greater than our minDistance place it else continue;
      {
        int cows=1;
        int distance=0;
        int lastPlaced = stalls[0];       
        for(int i=1;i<stalls.size();i++) // TC: O(n)
        {
            if(stalls[i] - lastPlaced >= minDistance)
            {
                cows++;
                lastPlaced = stalls[i]; 
            }
        }
        return cows;
      }

      int aggressiveCows(vector<int> &stalls, int k) { // we check if given the distance how many cows can we fit int the array, if it is greater than required we increase the distance else decrease it, we do this using binary search and the helper funcition which calculates how many cows can we fit, the twist was that we needed to first sort the array
        // TC: O(nlogn + nlog(max_element-min_element)), SC: O(1)
        int l=1;
        sort(stalls.begin(),stalls.end()); // TC: O(nlogn)
        int r = stalls.back() - stalls.front();
        int mid,ans,cowsFit;
        while(l<=r) // TC: O(nlog(max_element-min_element))
        {
            mid=l+(r-l)/2;
            cowsFit=calcCowsFit(stalls,mid); // TC: O(n)
            if(cowsFit==k)
            {
                ans=mid;
                l=mid+1;
            }
            else if(cowsFit<k)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if(cowsFit==k)
        {
            return ans;
        }
        else
        {
            return r;
        }
      }
};

int main()
{
   int n,k;
   cin>>n>>k;
   vector<int> stalls(n);
   for(int &element:stalls)
   {
    cin>>element;
   }
   Solution sol;
   int ans=sol.aggressiveCows(stalls,k);
   cout<<ans;
   return 0;
}