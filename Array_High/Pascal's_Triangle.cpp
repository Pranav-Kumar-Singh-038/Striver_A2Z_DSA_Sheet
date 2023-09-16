#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        for(int i=0;i<numRows;i++)
        {
            int val=1;
            vector<int> nums;
            for(int j=0;j<=i;j++)
            {
                nums.push_back(val);
                if (j != 0 && j != i-1) {
                    val = vec[i - 1][j - 1] + vec[i - 1][j];
                }

            }
            vec.push_back(nums);
        }
        return vec;
    }
};

int main() {
    int numRows;
    cin>>numRows;
    //cout<<numRows;
    Solution sol;
    vector<vector<int>> ans = sol.generate(numRows);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
