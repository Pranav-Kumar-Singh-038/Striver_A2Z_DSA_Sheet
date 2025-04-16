#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int calcReqDays(vector<int>& weights, int shipWeight, int reqDays) // The logic is simple that we continue adding weights until ship capacity if it exceeds count a day, reset totalweight variable and reduce i as it will not count the weight which caused it to exceed, edge case if individual weight exceeds the ship weight the return from function with days>shipweight
        {
           int totalWeight=0;
           int days=0;
           for(int i=0;i<weights.size();i++)
           {
            if(weights[i]>shipWeight)
            {
                days=reqDays+1;
                break;
            }
            int weight=weights[i];
            totalWeight+=weight;
            if(totalWeight==shipWeight)
            {
                totalWeight=0;
                days++;
            }
            else if(totalWeight>shipWeight)
            {
                totalWeight=0;
                days++;
                i--;
            }
           }
           if(totalWeight>0)
           {
            days++;
           }
           return days;
        }

        int shipWithinDays(vector<int>& weights, int days) { // Same as Koko eating bananas but the twist is that we go from 1 to accumulation of all weights, and check the required days for the given ship weight, the twist is in the helper function
            int l=1;
            int r=accumulate(weights.begin(),weights.end(),0); // TC: O(n)
            int shipWeight,ans,reqDays;
            while(l<=r) // TC: O(nlog(accumulate(weights)))
            {
                shipWeight=l+(r-l)/2;
                reqDays=calcReqDays(weights,shipWeight,days); // TC :O(n)
                if(reqDays==days)
                {
                    ans=shipWeight;
                    r=shipWeight-1;
                }
                else if(reqDays<days)
                {
                    r=shipWeight-1;
                }
                else
                {
                    l=shipWeight+1;
                }
            }
            if(reqDays==days)
            {
                return ans;
            }
            else 
            {
                return l;
            }
        }
};


int main()
{
  int n,days;
  cin>>n>>days;
  vector<int> weights(n);
  for(int &element:weights)
  {
    cin>>element;
  }
  Solution sol;
  int ans=sol.shipWithinDays(weights,days);
  cout<<ans;
  return 0;
}