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
    vector<int> postorderTraversal(TreeNode *root) // Using Iteration 2 stack
    {
        // TC: O(n), SC: O(2*n)
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        stack<TreeNode *> stk1;
        stack<TreeNode *> stk2;
        stk1.push(root);
        while (!stk1.empty())
        {
            TreeNode *current = stk1.top();
            stk1.pop();
            stk2.push(current);
            if (current->left)
            {
                stk1.push(current->left);
            }
            if (current->right)
            {
                stk1.push(current->right);
            }
        }
        while (!stk2.empty())
        {
            ans.push_back(stk2.top()->val);
            stk2.pop();
        }
        return ans;
    }

    vector<int> postorderTraversal1(TreeNode *root) // Using Recursion
    {
        // TC: O(n), SC: O(2*n)
        if (root == NULL)
        {
            return {};
        }
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }

    void postOrder(TreeNode *root, vector<int> &ans) // recursive function
    {
        if (root == NULL)
        {
            return;
        }

        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }

    TreeNode *createBinaryTree(vector<int> vec)
    {
        if (vec.size() == 0)
        {
            return NULL;
        }
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(vec[0]);
        TreeNode *current;
        q.push(root);
        int i = 1;
        while (i < vec.size())
        {
            current = q.front();
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
    vector<int> ans = sol.postorderTraversal(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
