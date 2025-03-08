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
    int maxDiameter(TreeNode *root) // recursive DFS
    {
        // TC: O(n), SC: O(n) (skewed)
        if(root==NULL)
        {
            return 0;
        }
        return 1+max(maxDiameter(root->left),maxDiameter(root->right));
    }

    int maxDepth1(TreeNode *root) // Iterative BFS
    {
        // TC: O(n), SC: O(n/2)(balanced)
        if (root == NULL)
        {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        TreeNode *current;
        while (!q.empty())
        {
            depth++;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                current = q.front();
                q.pop();
                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
            }
        }
        return depth;
    }

    TreeNode *createBinaryTree(vector<int> vec)
    {
        if (vec.empty())
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(vec[0]);
        TreeNode *current;
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;
        while (i < vec.size())
        {
            current = q.front();
            q.pop();
            if (vec[i] != -1 && i < vec.size())
            {
                current->left = new TreeNode(vec[i]);
                q.push(current->left);
            }
            i++;
            if (vec[i] != -1 && i < vec.size())
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
    int ans = sol.maxDiameter(root);
    cout << ans;
}


