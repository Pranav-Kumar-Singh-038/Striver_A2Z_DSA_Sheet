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
    int widthOfBinaryTree(TreeNode *root)
    {
        //The problem with max size of queue method is that the tree has null children
        // the problem with horizontal distance is that multiple nodes can have same horizontal distance
        // we use the index of the node in a level to find the width of the level
        // we push the nodes into queue with their children the left child is at index
        // 2*i+1 and right child at 2*i+2(0 based indexing), we find the width of a level
        // by checking the difference between the first and the last node of that level
        // but the indexes may reach very long values (more than long long can hold, simply because there might be null in between)
        // since we only need to calculate the gap between the first and last nodes of each level
        // we subtract the indexes by the index of the first nodex, effectively making size of
        // indexes to be small
        // TC:O(n), SC:O(n)
        if (!root)
        {
            return 0;
        }

        queue<pair<TreeNode *, long long>> q; // SC:O(n)
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) // TC:O(n)(amortized)
        {
            int size = q.size();
            long long minIndex = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) 
            {
                TreeNode *curr = q.front().first; 
                long long index = q.front().second - minIndex;
                q.pop();

                if (i == 0)
                {
                    first = index;
                }
                if (i == size - 1)
                {
                    last = index;
                }

                if (curr->left)
                {
                    q.push({curr->left, 2 * index + 1});
                }
                if (curr->right)
                {
                    q.push({curr->right, 2 * index + 2});
                }
            }

            maxWidth = max(maxWidth, (int)(last - first + 1));
        }

        return maxWidth;
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
    int ans = sol.widthOfBinaryTree(root);
    cout << ans;
}