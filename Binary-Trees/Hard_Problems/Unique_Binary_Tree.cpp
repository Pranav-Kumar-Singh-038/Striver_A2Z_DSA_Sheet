#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int a, int b) // 1= Preorder, 2 = Inorder, 3 = postorder, A binary tree can only be constructed if you get an inorder and a post or pre order traversal, else not. Else you can create multiple trees with the same traversals not unique.
    {
        // TC: O(1), SC: O(1)
       if((a==1 && b==3 )|| (a==3 && b==1) || (a==b))
       {
           return false;
       }
       return true;
    }
};

int main()
{
    int a,b;
    cin>>a>>b;
    Solution sol;
    bool ans = sol.isPossible(a,b);
    cout << ans;
}
