#include <bits/stdc++.h>
using namespace std;
 
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) { // Look from back side and keep storing the largest till that point
        // TC: O(1.5n), SC: O(1) (not counting ans array as it is necessary)
        int largest=INT_MIN;
        vector<int> ans;
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(arr[i]>=largest)
            {
              ans.push_back(arr[i]);
              largest=arr[i];
            }
        }
        reverse(ans.begin(),ans.end()); // takes O(n/2) internally but still better than manually doing the same as it is implemented at compiler level (Optimized at the compiler level, making it potentially faster in real-world execution.)
        return ans;
    }

};


int main() {
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int &x:vec)
    {
        cin>>x;
    }
    Solution sol;
    vector<int> ans=sol.leaders(vec);
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}
