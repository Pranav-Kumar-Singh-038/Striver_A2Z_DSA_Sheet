#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void storeCombinations(int k,int sum, int currSum, int index, vector<int>& sumArray, vector<vector<int>>& ans)
    {
        // TC: O(2^k), where k is the size of array required, but it can be maximum be 9, so O(2^9), SC: O(k) stack size, O( k·C(9,k)) result size
       if(currSum==sum && sumArray.size()==k)
        {
            ans.push_back(sumArray);
            return;
        }
        if(index>9 || currSum>sum || sumArray.size()>k)
        {
            return;
        }
        //include
        sumArray.push_back(index);
        storeCombinations(k,sum,currSum+index,index+1,sumArray,ans);
        sumArray.pop_back();

        //exclude
        storeCombinations(k,sum,currSum,index+1,sumArray,ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        int currSum=0,index=1;
        vector<int> sumArray;
        vector<vector<int>> ans;
        storeCombinations(k,n,currSum,index,sumArray,ans);
        return ans;
    }
};

int main()
{
  int k,n;
  cin>>k>>n;

  Solution sol;
  vector<vector<int>> ans=sol.combinationSum3(k,n);
  for(auto &vec:ans)
  {
    for(int &it:vec)
    {
        cout<<it<<" ";
    }
    cout<<endl;
  }
  return 0;
}