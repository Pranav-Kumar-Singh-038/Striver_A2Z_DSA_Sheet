#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int newSize = 1;
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[j - 1]) {
                nums[newSize] = nums[j];
                newSize++;
            }
        }
        
        nums.resize(newSize);
        
        return newSize;
    }
};

//Time complexity: O(n)
//space complexity: O(1)

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    
    Solution sol;
    int ans = sol.removeDuplicates(vec);

    for (int i = 0; i < ans; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    return 0;
}
