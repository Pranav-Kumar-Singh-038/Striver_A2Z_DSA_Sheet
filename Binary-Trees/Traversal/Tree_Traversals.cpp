#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode* root,vector<int> &inorder) // TC: O(n), SC: O(2*n)
{
 if(root==NULL)
 {
    return ;
 }

 inorderTraversal(root->left,inorder);
 inorder.push_back(root->data);
 inorderTraversal(root->right,inorder);
}

void preorderTraversal(TreeNode* root,vector<int> &preorder) // TC: O(n), SC: O(2*n)
{
  if(root==NULL)
  {
    return ;
  }

  preorder.push_back(root->data);
  preorderTraversal(root->left,preorder);
  preorderTraversal(root->right,preorder);
}

void postorderTraversal(TreeNode* root,vector<int> &postorder) // TC: O(n), SC: O(2*n)
{
    if(root==NULL)
    {
      return;
    }
  
    postorderTraversal(root->left,postorder);
    postorderTraversal(root->right,postorder);
    postorder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root) // TC: O(3*n), SC: O(6*n)
{
    vector<int> inorder,preorder,postorder;
    inorderTraversal(root,inorder);
    preorderTraversal(root,preorder);
    postorderTraversal(root,postorder);
    return {inorder,preorder,postorder};
}

TreeNode *createBinaryTree(vector<int> values) // TC: O(n), SC: O(n/2 + n)
{
   if(values.empty() || values[0] == -1)
   {
    return NULL;
   }

   TreeNode* root=new TreeNode(values[0]);
   queue<TreeNode *> q;
   q.push(root);
   int i=1;
   while(i<values.size())
   {
    TreeNode* node=q.front();
    q.pop();

    if(i < values.size() && values[i]!=-1)
    {
        node->left=new TreeNode(values[i]);
        q.push(node->left);
    }
    i++;

    if(i<values.size() && values[i]!=-1)
    {
        node->right=new TreeNode(values[i]);
        q.push(node->right);
    }
    i++;
   }
   return root;
}

int main()
{
    int n;
    cin>>n;
    vector<int> values(n);
    for(int &x:values)
    {
        cin>>x;
    }
    TreeNode* root=createBinaryTree(values);
    vector<vector<int>> ans=getTreeTraversal(root);
    for(auto it:ans)
    {
        for(auto i:it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}