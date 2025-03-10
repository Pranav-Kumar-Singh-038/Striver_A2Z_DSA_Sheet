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
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
        {
            return true;
        }
        if (!left || !right)
        {
            return false;
        }
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric2(TreeNode *root) // Recursive
    {
        // TC: O(N), SC: O(n) (skewed), O(h) average so better
        if (!root)
        {
            return true;
        }
        return isMirror(root->left, root->right);
    }

    bool isSymmetric(TreeNode *root) // Iterative
    {
        // TC: O(n), SC: O(n)
        if (!root)
        {
            return true;
        }

        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            TreeNode *leftNode = q.front();
            q.pop();
            TreeNode *rightNode = q.front();
            q.pop();

            if (!leftNode && !rightNode)
            {
                continue;
            }

            if (!leftNode || !rightNode || leftNode->val != rightNode->val)
            {
                return false;
            }

            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }

        return true;
    }

    TreeNode *createBinaryTree(vector<optional<int>> vec)
    {
        if (vec.empty() || !vec[0].has_value())
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(vec[0].value());
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *current;
        int i = 1;
        while (i < vec.size())
        {
            current = q.front();
            q.pop();
            if (vec[i].has_value() && i < vec.size())
            {
                current->left = new TreeNode(vec[i].value());
                q.push(current->left);
            }
            i++;
            if (vec[i].has_value() && i < vec.size())
            {
                current->right = new TreeNode(vec[i].value());
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
    vector<optional<int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (x == "null")
        {
            vec[i] = nullopt;
        }
        else
        {
            vec[i] = stoi(x);
        }
    }
    Solution sol;
    TreeNode *root = sol.createBinaryTree(vec);
    bool ans = sol.isSymmetric(root);
    cout << ans;
}


