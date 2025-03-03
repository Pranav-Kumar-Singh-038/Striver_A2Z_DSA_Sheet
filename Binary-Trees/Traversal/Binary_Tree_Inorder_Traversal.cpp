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
    void inorder(TreeNode *root, vector<int> &vec) // Recursive Logic
    {
       if(root==NULL)
       {
        return;
       }
       inorder(root->left,vec);
       vec.push_back(root->val);
       inorder(root->right,vec);
    }

    vector<int> inorderTraversal1(TreeNode *root) // Traverse using recursion
    {
      // TC: O(n), SC: O(2*n)
      vector<int> vec;
      inorder(root, vec);
      return vec;
    }

    vector<int> inorderTraversal(TreeNode *root) // Iterative
    {
      // TC: O(n), SC: O(2*n)
      vector<int> ans;
      TreeNode* current=root;
      stack<TreeNode *> stk;
      while (current != NULL || !stk.empty()) 
      {
          while (current != NULL) 
          {
              stk.push(current);
              current = current->left;
          }
          current = stk.top();
          stk.pop();
          ans.push_back(current->val);
  
          current = current->right;
      }
      return ans;
    }

    TreeNode *createBinaryTree(vector<int> vec)
    {
        if(vec.empty())
        {
            return NULL;
        }
        queue<TreeNode *> q;
        TreeNode* root=new TreeNode(vec[0]);
        TreeNode* current=root;
        q.push(current);
        int i=1;
        while(i<vec.size())
        {
            current=q.front();
            q.pop();
            if(i<vec.size() && vec[i]!=-1)
            {
                current->left=new TreeNode(vec[i]);
                q.push(current->left);
            }
            i++;

            if(i<vec.size() && vec[i]!=-1)
            {
                current->right=new TreeNode(vec[i]);
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
    vector<int> ans = sol.inorderTraversal(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
