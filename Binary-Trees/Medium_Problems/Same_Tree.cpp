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
    bool isSameTree2(TreeNode *p, TreeNode *q) // Recursive
    {
        // TC: O(min(n,m)), SC: O(min(h1,h2))
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL)
        {
            return false;
        }
        if (p->val == q->val)
        {
            return isSameTree2(p->left, q->left) && isSameTree2(p->right, q->right);
        }
        return false;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) //  a level-order traversal of two binary trees using BFS, comparing corresponding nodes and ensuring structural similarity at each level.
    {
        // SC: O(2*n), TC: O(n)
        if (!p && !q)
        {
            return true;
        }
        if (!p || !q)
        {
            return false;
        }
        TreeNode *current1;
        TreeNode *current2;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty())
        {
            int levelSize = q1.size();
            for (int i = 0; i < levelSize; i++)
            {
                current1 = q1.front();
                current2 = q2.front();
                q1.pop();
                q2.pop();
                if (current1->val != current2->val)
                {
                    return false;
                }
                if (current1->left && current2->left)
                {
                    q1.push(current1->left);
                    q2.push(current2->left);
                }
                else if (current1->left || current2->left)
                {
                    return false;
                }

                if (current1->right && current2->right)
                {
                    q1.push(current1->right);
                    q2.push(current2->right);
                }
                else if (current1->right || current2->right)
                {
                    return false;
                }
            }
        }
        return q1.empty() && q2.empty();
    }

    TreeNode *createBinaryTree(vector<optional<int>> vec)
    {
        if (vec.empty() || !vec[0].has_value())
        {
            return NULL;
        }

        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(vec[0].value());
        int i = 1;
        q.push(root);
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
    int n, m;
    cin >> n >> m;
    vector<optional<int>> vec1(n); // vector<optional<int>> is a dynamic array where each element can either hold an int value or be nullopt, making it useful for representing binary trees with missing (NULL) nodes.
    for (int i = 0; i < n; i++)
    {
        string value;
        cin >> value;

        if (value == "NULL")
        {
            vec1[i] = nullopt;
        }
        else
        {
            vec1[i] = stoi(value);
        }
    }
    vector<optional<int>> vec2(n);
    for (int i = 0; i < m; i++)
    {
        string value;
        cin >> value;

        if (value == "NULL")
        {
            vec2[i] = nullopt;
        }
        else
        {
            vec2[i] = stoi(value);
        }
    }
    Solution sol;
    TreeNode *root1 = sol.createBinaryTree(vec1);
    TreeNode *root2 = sol.createBinaryTree(vec2);

    bool ans = sol.isSameTree(root1, root2);
    cout << ans;
}
