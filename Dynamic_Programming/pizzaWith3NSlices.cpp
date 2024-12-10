class Solution {
public:
    int solve(vector<int>& slices, int picksLeft, int index, int endIndex, vector<vector<int>>& memo) {
        if (picksLeft == 0 || index > endIndex) {
            return 0;
        }
        if(memo[index][picksLeft]!=-1)
        {
            return memo[index][picksLeft];
        }
        int take = slices[index] + solve(slices, picksLeft - 1, index + 2, endIndex, memo);
        int skip = 0 + solve(slices, picksLeft, index + 1, endIndex, memo);
        return memo[index][picksLeft]=max(take, skip);
    }

    int maxSizeSlices(vector<int>& slices) {
        int picks = slices.size() / 3;
        vector<vector<int>> memo1(slices.size(), vector<int>(picks+1, -1));
        vector<vector<int>> memo2(slices.size(), vector<int>(picks+1, -1));
        int scen1 = solve(slices, picks, 0, slices.size() - 2, memo1);
        int scen2 = solve(slices, picks, 1, slices.size() - 1, memo2);
        return max(scen1, scen2);
    }
};