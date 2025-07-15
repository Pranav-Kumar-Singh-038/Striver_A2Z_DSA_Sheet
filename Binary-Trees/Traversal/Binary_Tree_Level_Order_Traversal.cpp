#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // we use a queue for level order or breadth first search, we push the root
        // pop it, push its left and right node, pop them one by one, push their left
        // and right nodes, simple, only to track the level, when you enter a level, 
        // use a forloop to pop all nodes in that level at once, for the second level
        // the level size is equal to the queue size, we pop all one by one, pop their
        // left and right, then push it to ans vector as a vector
        // TC:O(n), SC:O(3n) = O(n)
        vector<vector<int>> ans; // SC:O(n)
        if (!root)
        {
            return ans;
        }

        queue<TreeNode *> q; // SC:O(n)
        q.push(root);

        while (!q.empty()) // TC:O(n)
        {
            int levelSize = q.size();
            vector<int> vec; // SC:O(n/2)

            for (int i = 0; i < levelSize; ++i) // TC:O(n/2)
            {
                TreeNode *node = q.front();
                q.pop();
                vec.push_back(node->val);

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            ans.push_back(vec);
        }

        return ans;
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
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    Solution sol;
    TreeNode *root = sol.createBinaryTree(vec);
    vector<vector<int>> ans = sol.levelOrder(root);
    for (auto &val : ans)
    {
        for (auto &it : val)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
