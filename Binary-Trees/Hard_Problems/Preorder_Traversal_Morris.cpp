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
    vector<int> preorderTraversal(TreeNode *root) //Morris Preorder Traversal algorithm traverses the tree using threaded binary tree links to avoid extra space, visiting each node twice—first to process it and create a temporary thread, and second to remove the thread and move right.
    {
        // TC: O(2n), SC: O(1)
        TreeNode* curr=root;
        vector<int> ans;
        while(curr!=NULL)
        {
            if(curr->left)
            {
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
            else
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
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

        if (value == "null")
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
    vector<int> ans = sol.preorderTraversal(root);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
}