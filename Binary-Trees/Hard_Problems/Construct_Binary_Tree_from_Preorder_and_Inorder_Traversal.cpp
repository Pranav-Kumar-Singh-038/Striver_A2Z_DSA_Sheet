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
    void createBT(vector<int> &preorder, vector<int> &inorder, TreeNode *&node, int inStart, int inEnd, int &preIndex, unordered_map<int, int> &inMap)
    {
        // TC:O(n), SC:O(n)(worst)
        if (inStart > inEnd || preIndex >= preorder.size())
        {
            return;
        }

        node = new TreeNode(preorder[preIndex]);
        int currVal = preorder[preIndex];
        int inIndex = inMap[currVal]; // TC:O(1)

        preIndex++;

        if (inStart <= inIndex - 1)
        {
            createBT(preorder, inorder, node->left, inStart, inIndex - 1, preIndex, inMap);
        }
        if (inIndex + 1 <= inEnd)
        {
            createBT(preorder, inorder, node->right, inIndex + 1, inEnd, preIndex, inMap);
        }
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // The problem is solved recursively by breaking it down into subproblems:
        // At each step, we identify the current root node from the preorder traversal,
        // and then use the inorder traversal to determine the boundaries of the left
        // and right subtrees.

        // Preorder traversal gives us the root node first, so we maintain a global
        // index (preIndex) that moves forward as we build the tree.

        // To quickly find the position of a node in the inorder array, we use an
        // unordered_map which allows constant time lookup (O(1)).

        // Once we know the index of the root in the inorder array, we can divide the
        // inorder array into two parts:
        //   - Left subtree: inorder[inStart ... inIndex - 1]
        //   - Right subtree: inorder[inIndex + 1 ... inEnd]

        // We recursively build the left and right subtrees by passing the correct
        // inorder boundaries and incrementing the preorder index.

        // The recursion stops when the inorder range becomes invalid (inStart > inEnd),
        // which means we've reached a leaf node.
        // TC:O(2n)=O(n), SC:O(2n)=O(n)
        int preIndex = 0;
        unordered_map<int, int> inMap;           // SC:O(n)
        for (int i = 0; i < inorder.size(); i++) // TC:O(n)
        {
            inMap[inorder[i]] = i;
        }

        TreeNode *root = nullptr;
        createBT(preorder, inorder, root, 0, inorder.size() - 1, preIndex, inMap); // TC:O(n), SC:O(n)
        return root;
    }

    void printBT(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                cout << current->val << " ";
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
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int &it : preorder)
    {
        cin >> it;
    }
    Solution sol;
    TreeNode *ans = sol.buildTree(preorder, inorder);
    sol.printBT(ans);
}