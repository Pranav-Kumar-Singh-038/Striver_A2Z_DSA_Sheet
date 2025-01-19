#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        // TC: O(n) SC: O(1)
        int depth=0;
        int maxDepth=0;
        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='(')
           {
            depth++;
           }
           else if(s[i]==')')
           {
            depth--;
           }
           maxDepth=max(depth, maxDepth);
        }
        return maxDepth;
    }
};

int main()
{
    string s;
    cin>>s;

    Solution sol;
    int ans=sol.maxDepth(s);
    cout<<ans<<endl;
}