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
    void createBT(vector<int> &inorder, vector<int> &postorder, int &postIndex, int inStart, int inEnd, TreeNode *&node, unordered_map<int, int> &inMap)
    {
        // TC:O(n), SC:O(n)(worst)
        if (inStart > inEnd || inEnd < inStart || postIndex >= postorder.size())
        {
            return;
        }
        node = new TreeNode(postorder[postIndex]);
        int val = postorder[postIndex];
        int inIndex = inMap[val];
        postIndex--;
        if (inIndex <= inEnd)
        {
            createBT(inorder, postorder, postIndex, inIndex + 1, inEnd, node->right, inMap);
        }
        if (inIndex >= inStart)
        {
            createBT(inorder, postorder, postIndex, inStart, inIndex - 1, node->left, inMap);
        }
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // The only difference is since it is post order we traverse it from the back
        // the root we get are right first then left. so for the recursive call we
        // call the right subtree first

        // The problem is solved recursively by breaking it down into subproblems:
        // At each step, we identify the current root node from the postorder traversal,
        // and then use the inorder traversal to determine the boundaries of the left
        // and right subtrees.

        // postorder traversal gives us the root node first, so we maintain a global
        // index (posIndex) that moves backward as we build the tree.

        // To quickly find the position of a node in the inorder array, we use an
        // unordered_map which allows constant time lookup (O(1)).

        // Once we know the index of the root in the inorder array, we can divide the
        // inorder array into two parts:
        //   - Left subtree: inorder[inStart ... inIndex - 1]
        //   - Right subtree: inorder[inIndex + 1 ... inEnd]

        // We recursively build the left and right subtrees by passing the correct
        // inorder boundaries and decrementing the postorder index.

        // The recursion stops when the inorder range becomes invalid (inStart > inEnd),
        // which means we've reached a leaf node.
        // TC:O(2n)=O(n),SC:O(2n)=O(n)
        TreeNode *root = NULL;
        int postIndex = postorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;
        unordered_map<int, int> inMap;           // SC:O(n)
        for (int i = 0; i < inorder.size(); i++) // TC:O(n)
        {
            inMap[inorder[i]] = i;
        }
        createBT(inorder, postorder, postIndex, inStart, inEnd, root, inMap);
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
    vector<int> inorder(n), postorder(n);
    for (int &it : inorder)
    {
        cin >> it;
    }
    for (int &it : postorder)
    {
        cin >> it;
    }
    Solution sol;
    TreeNode *ans = sol.buildTree(inorder, postorder);
    sol.printBT(ans);
}