#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void storeCombinations(vector<int> &candidates,int target, int index, int currSum,vector<int> &candidateGroup,vector<vector<int>> &ans) // include and an exclude case, in include the only different we don't increase the index so that we can take the same number again and again until it exceeds currSum, also take two variable candidateGroup and ans to store the results
    {
        // TC: O(2^n), SC:O(target / min(candidates)) // because at worst we pick the smallest number until it equals target.
        if(currSum==target)
        {
         ans.push_back(candidateGroup);
         return;
        }
        if(currSum> target || index>=candidates.size())
        {
            return;
        }
        // include
        candidateGroup.push_back(candidates[index]);
        storeCombinations(candidates,target,index,currSum+candidates[index],candidateGroup,ans);
        candidateGroup.pop_back();

        // exclude
        storeCombinations(candidates,target,index+1,currSum,candidateGroup,ans);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0,currSum=0;
        vector<int> candidateGroup;
        vector<vector<int>> ans;
        storeCombinations(candidates, target, index,currSum,candidateGroup,ans);
        return ans;
    }
};

int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> vec(n);
  for(int &it:vec)
  {
    cin>>it;
  }

  Solution sol;
  vector<vector<int>> ans=sol.combinationSum(vec,k);
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