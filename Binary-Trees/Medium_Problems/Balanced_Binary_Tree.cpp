#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    int val;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    bool isBalanced(TreeNode *root) // using maximum depth, only when we get the diff to be -1 we return -1 which cascades into -1 as the final answer, else we return depth 
    {
        // TC: O(n), SC: O(n)
        return maxDiameter(root) != -1;
    }

    int maxDiameter(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftDepth = maxDiameter(root->left);
        if (leftDepth == -1)
        {
            return -1;
        }

        int rightDepth = maxDiameter(root->right);
        if (rightDepth == -1)
        {
            return -1;
        }

        if (abs(leftDepth - rightDepth) > 1)
        {
            return -1;
        }

        return 1 + max(leftDepth, rightDepth);
    }

    TreeNode *createBinaryTree(vector<int> vec)
    {
        if (vec.empty())
        {
            return NULL;
        }

        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(vec[0]);
        q.push(root);
        int i = 1;
        while (i < vec.size())
        {
            TreeNode *current = q.front();
            q.pop();
            if (i < vec.size() && vec[i] != -1)
            {
                current->left = new TreeNode(vec[i]);
                q.push(current->left);
            }
            i++;
            if (i < vec.size() && vec[i] != -1)
            {
                current->right = new TreeNode(vec[i]);
                q.push(current->right);
            }
            i++;
        }
        return root;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &x : vec)
    {
        cin >> x;
    }
    Solution sol;
    TreeNode *root = sol.createBinaryTree(vec);
    bool ans = sol.isBalanced(root);
    cout << ans;
}
