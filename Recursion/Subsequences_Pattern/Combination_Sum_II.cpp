#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &candidates, int target, int start, vector<int> &curr, vector<vector<int>> &result) // // iterate the candidates, skip duplicates find the next piece of combination i.e  1 2 ... or 1 3 .. then via recursion all pattern of the combination will be generated, you have already skipped the duplicates so now, go on to 2 2 .. or 2 3 .. similarly, since the array is sorted you will generate a sorted list. // by popping after each loop you are already handling include and exclude logic
    {
        // TC: O(2^n) worst case (backtracking) + O(n log n) (sort), SC: 	O(k * 2^n) for result + O(n) recursion, k is the average size of a valid combination (often small, like 2–4).
        //2^n = 2^10 = 1024 paths (all subsets of 10 elements).
        if (target == 0)
        {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) 
        {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (candidates[i] > target)
            {
                break;
            }
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, curr, result); // move to next index
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // sort first
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, result);
        return result;
    }

    void storeCombinations(vector<int> &candidates, int target, int index, int currSum, vector<int> candidateGroup, set<vector<int>> &ans) // include and an exclude case, in include the only different we don't increase the index so that we can take the same number again and again until it exceeds currSum, also take two variable candidateGroup and ans to store the results
    {
        // TC: O(2^n), SC:O(target / min(candidates)) // because at worst we pick the smallest number until it equals target.
        if (currSum == target)
        {
            sort(candidateGroup.begin(), candidateGroup.end());
            ans.insert(candidateGroup);
            return;
        }
        if (currSum > target || index >= candidates.size())
        {
            return;
        }
        // include
        candidateGroup.push_back(candidates[index]);
        storeCombinations(candidates, target, index + 1, currSum + candidates[index], candidateGroup, ans);
        candidateGroup.pop_back();

        // exclude
        storeCombinations(candidates, target, index + 1, currSum, candidateGroup, ans);
        return;
    }

    vector<vector<int>> combinationSum2_1(vector<int> &candidates, int target)
    {
        int index = 0, currSum = 0;
        vector<int> candidateGroup;
        set<vector<int>> mySet;
        storeCombinations(candidates, target, index, currSum, candidateGroup, mySet);
        vector<vector<int>> ans(mySet.begin(), mySet.end());
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int &it : vec)
    {
        cin >> it;
    }

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum2(vec, k);
    for (auto &vec : ans)
    {
        for (int &it : vec)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}