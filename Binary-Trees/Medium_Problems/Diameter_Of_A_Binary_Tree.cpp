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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode *root) // Using max Depth, also calculate the diameter of every node while calculating
    // The left and right depth, this will prevent calling every node for diameter as it is done in single traversal.
    {
        // TC: O(n), SC: O(n)
        if (root == NULL)
        {
            return 0;
        }
        maxDepth(root);
        return diameter;
    }

    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        diameter = max(diameter, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }

    TreeNode *createBinaryTree(const vector<optional<int>> &vec)
    {
        if (vec.empty() || !vec[0].has_value())
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(vec[0].value());
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;

        while (i < vec.size())
        {
            TreeNode *current = q.front();
            q.pop();

            if (i < vec.size() && vec[i].has_value())
            {
                current->left = new TreeNode(vec[i].value());
                q.push(current->left);
            }
            i++;

            if (i < vec.size() && vec[i].has_value())
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
        string value;
        cin >> value;

        if (value == "NULL")
        {
            vec[i] = nullopt;
        }
        else
        {
            vec[i] = stoi(value);
        }
    }
    Solution sol;
    TreeNode *root = sol.createBinaryTree(vec);
    int ans = sol.diameterOfBinaryTree(root);
    cout << ans;
}


