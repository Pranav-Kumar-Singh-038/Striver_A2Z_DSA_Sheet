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
    int countNodes(TreeNode *root) // Get the height and apply binary search on the last level, number of nodes in last level is 2^height -1, if the node doesn't exist move left, else right, untill left>right.
    {
        // TC: O(logn^2), SC: O(1)
        if (!root)
        {
            return 0;
        }

        int height = getHeight(root); // logn

        if (height == 0)
        {
            return 1;
        }

        int low = 0, high = (1 << height) - 1;
        while (low <= high) // logn
        {
            int mid = low + (high - low) / 2;
            if (nodeExists(mid, height, root)) // logn
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return (1 << height) - 1 + low;
    }

    int getHeight(TreeNode *root) // Since complete binary tree, traverse to the leftmost and determine depth, gives 1 less height
    {
        // TC: O(logn), SC: O(1)
        int height = 0;
        while (root->left)
        {
            height++;
            root = root->left;
        }
        return height;
    }

    bool nodeExists(int idx, int height, TreeNode *root) // move according to the msb bit, and change it at each iteration for the depth of tree, if 1 go right, else left
    { 
        // TC: O(logn), SC: O(1)
        int leftMostSetBit=1 << (height-1);
        for (int i = 0; i < height; i++)
        {
            if (idx & leftMostSetBit)
            {                      
                root = root->right; 
            }
            else
            {
                root = root->left; 
            }
            idx <<= 1;
        }
        return root != NULL;
    }

    int countNodes1(TreeNode *root) // BFS traversal
    {
        // TC: O(n), SC: O(n)
        if (root == NULL)
        {
            return 0;
        }
        TreeNode *current;
        queue<TreeNode *> q;
        q.push(root);
        int nodes = 0;
        while (!q.empty())
        {
            int ls = q.size();
            nodes += ls;
            for (int i = 0; i < ls; i++)
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
        return nodes;
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
    int ans = sol.countNodes(root);
    cout << ans;
}
