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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // the idea is we do a dfs traversal, if we reach after a leaf, ie. null, we return it
        // if we find any of the targetNodes we return them, if at a node we get
        // a value from either left or right we return the value, this means that
        // either lca is in the node in which we got the value and is the value which
        // we got, or we found one of the targets, if at a node we get both values
        // that is the lca and return it;

        // TC:O(n), SC:O(n)
        if (root == NULL || root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }

    bool recordPath(TreeNode *root, TreeNode *targetNode, vector<TreeNode *> &path)
    {
        // TC:O(n), SC:O(n)
        if (root == NULL)
        {
            return false;
        }

        path.push_back(root);

        if (root == targetNode)
        {
            return true;
        }

        if (recordPath(root->left, targetNode, path) || recordPath(root->right, targetNode, path))
        {
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor1(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // suboptimal
        // The basic idea is to find the nodes and record there paths, the node after
        // which their values change is called there ancestor
        // the record the path of finding them, we make a bool function which returns true
        // when found, if we are at a leaf return false, at each recursive call, we push
        // the current node into the path, assuming it is a valid path, then we recursively
        // call both for left and right nodes, if any one comes true , thus cancelling any further
        // edits to path, if not found we pop back the node and return false, this removes the nodes
        // from processing if both paths came out to be false,
        // TC:O(3n)=O(n), SC:O(4n)=O(n)
        vector<TreeNode *> path1, path2; // SC:O(2n)
        recordPath(root, p, path1);      // TC:O(n), SC:O(n)
        recordPath(root, q, path2);      // TC:O(n), SC:O(n)
        TreeNode *ans = NULL;
        int shorterPath = min(path1.size(), path2.size());
        for (int i = 0; i < shorterPath; i++) // TC:O(n)
        {
            if (path1[i] != path2[i])
            {
                break;
            }
            ans = path1[i];
        }
        return ans;
    }

    vector<TreeNode *> createBinaryTree(const vector<string> &vec, int val1, int val2)
    {
        if (vec.empty() || vec[0] == "null")
        {
            return {NULL, NULL, NULL};
        }
        TreeNode *node1, *node2;
        TreeNode *root = new TreeNode(stoi(vec[0]));
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;

        while (i < vec.size())
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->val == val1)
            {
                node1 = current;
            }
            if (current->val == val2)
            {
                node2 = current;
            }

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
        return {root, node1, node2};
    }
};

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<string> vec(n);
    for (string &x : vec)
    {
        cin >> x;
    }
    Solution sol;
    vector<TreeNode *> nodes = sol.createBinaryTree(vec, p, q);
    TreeNode *root = nodes[0];
    TreeNode *node1 = nodes[1];
    TreeNode *node2 = nodes[2];
    TreeNode *ans = sol.lowestCommonAncestor(root, node1, node2);
    cout << ans->val;
}