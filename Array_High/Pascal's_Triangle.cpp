#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        return {{1,2,3},{4,5,6}};
    }
};

int main() {
    int numRows;
    cin>>numRows;
    cout<<numRows;
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
