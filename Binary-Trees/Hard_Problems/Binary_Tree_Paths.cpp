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
    void dfsTraversal(TreeNode *node, vector<string> &vec, string str)
    {
        // TC:O(n), SC:O(n)(worst)
        if (node == NULL)
        {
            return;
        }
        if (node->left == NULL && node->right == NULL)
        {
            str += to_string(node->val);
            vec.push_back(str);
            return;
        }

        str += to_string(node->val);
        str += "->";
        dfsTraversal(node->left, vec, str);
        dfsTraversal(node->right, vec, str);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        // we need to visit all paths so use dfs, if node is null we return, 
        // if node is a leaf, add the node value to string and push to vector , return
        // else we add each node value to string, then traverse left most first than right most
        // normal dfs traversal.
        // TC:O(n), SC:O(3n)=O(n)
        vector<string> vec; // SC:O(n)
        string str; // SC:O(n)
        dfsTraversal(root, vec, str); // TC:O(n), SC:O(n)
        return vec;
    }

    TreeNode *createBinaryTree(const vector<string> &vec)
    {
        if (vec.empty() || vec[0] == "null")
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(stoi(vec[0]));
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;

        while (i < vec.size())
        {
            TreeNode *current = q.front();
            q.pop();

            if (i < vec.size() && vec[i] != "null")
            {
                current->left = new TreeNode(stoi(vec[i]));
                q.push(current->left);
            }
            i++;

            if (i < vec.size() && vec[i] != "null")
            {
                current->right = new TreeNode(stoi(vec[i]));
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
    vector<string> vec(n);
    for (string &x : vec)
    {
        cin >> x;
    }
    Solution sol;
    TreeNode *root = sol.createBinaryTree(vec);
    vector<string> ans = sol.binaryTreePaths(root);
    for (auto &it : ans)
    {
        cout << it << endl;
    }
}