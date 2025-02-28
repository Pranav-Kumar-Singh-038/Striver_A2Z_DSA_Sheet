#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root) // TC: O(n), SC: O(2*n)
    {
        vector<int> preorder;
        stack<TreeNode *> stk;
        while(root || !stk.empty())
        {
            if(root!=NULL)
            {
                if(root->right)
                {
                    stk.push(root->right);
                }
              preorder.push_back(root->val);
              root=root->left;
            }
            else
            {
                root=stk.top();
                stk.pop();
            }
        }
        return preorder;
    }

    vector<int> preorderTraversal1(TreeNode *root) // TC: O(n), SC: O(2*n)
    {
        vector<int> preorder;
        preorderTree(root, preorder);
        return preorder;
    }

    void preorderTree(TreeNode *root, vector<int> &preorder)
    {
        if (root == NULL)
        {
            return;
        }

        preorder.push_back(root->val);
        preorderTree(root->left, preorder);
        preorderTree(root->right, preorder);
    }

    TreeNode *createBinaryTree(vector<int> vec)
    {
        TreeNode *root = new TreeNode(vec[0]);
        queue<TreeNode *> q;
        int i = 1;
        q.push(root);
        while (i < vec.size())
        {
            TreeNode *node = q.front();
            q.pop();

            if (i < vec.size() && vec[i] != -1)
            {
                node->left = new TreeNode(vec[i]);
                q.push(node->left);
            }
            i++;

            if (i < vec.size() && vec[i] != -1)
            {
                node->right = new TreeNode(vec[i]);
                q.push(node->right);
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
    vector<int> ans = sol.preorderTraversal(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}