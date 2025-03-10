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
    int countNodes(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
    }

    int maxDepth(TreeNode *node)
    {
        if(node==NULL)
        {
            return 0;
        }

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
    bool ans = sol.countNodes(root);
    cout << ans;
}
