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

//     Most push_back() operations are O(1)
//     But occasionally, the vector resizes → takes O(n) time
//     Still, over n insertions, the average time per insertion remains O(1)
//  So push_back() is said to have amortized O(1) time complexity.

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        // TC:O(n), SC:O(2n)= O(n)
        vector<int> ans; // SC:O(n)
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q; // SC:O(n)
        q.push(root);
        while (!q.empty()) // TC:O(n)(amortized) Amortized complexity means the average cost per operation over a sequence of operations, even if some individual operations are more expensive.)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
                if (i == size - 1)
                {
                    ans.push_back(current->val);
                }
            }
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
    for (string &x : vec)
    {
        cin >> x;
    }
    Solution sol;
    TreeNode *root = sol.createBinaryTree(vec);
    vector<int> ans = sol.rightSideView(root);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
}
