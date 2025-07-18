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
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // the idea is that to get the nodes at a certain level from a given node
        // we need to start from that node and move outwards, that is we need to move
        // from a node to its parent, but it is not possible in a tree data structure
        // so we need to make an unordered_map of child->parent, this helps us move to
        // the parent, we traverse once using bfs, and make this map, then we start from the target node
        // and do bfs traversal from it, we push its left child, right child and its parent
        // and continue to do so. when we reach the required level we break, and output
        // the content of the queue
        // TC:O(3n)=O(n), SC:O(5n)=O(n)
        queue<TreeNode*> q; //SC:O(n)
        unordered_map<TreeNode*,TreeNode*> parent; // SC:O(n)
        q.push(root);
        parent[root]=NULL;
        while(!q.empty()) // TC:O(n) amortized
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* current=q.front();
                q.pop();
                if(current->left)
                {
                    parent[current->left]=current;
                    q.push(current->left);
                }
                if(current->right)
                {
                    parent[current->right]=current;
                    q.push(current->right);
                }
            }
        }
        vector<int> ans; // SC:O(n)
        int distance=0;
        queue<TreeNode*> q2; // SC:O(n)
        unordered_map<TreeNode*,bool> visited; // SC:O(n)
        q2.push(target);
        while(!q2.empty()) // TC:O(n) amortized
        {
            int size=q2.size();
            // cout<<size<<endl;
            if(distance==k)
            {
                break;
            }
            for(int i=0;i<size;i++)
            {
                TreeNode* current=q2.front();
                q2.pop();
                visited[current]=true;
                if(current->left && visited[current->left]==false)
                {
                    q2.push(current->left);
                }
                if(current->right && visited[current->right]==false)
                {
                    q2.push(current->right);
                }
                if(parent[current] && visited[parent[current]]==false)
                {
                    q2.push(parent[current]);
                }
            }
            distance++;
        }
        while(!q2.empty()) // TC:O(n)
        {
          TreeNode* current=q2.front();
          q2.pop();
          ans.push_back(current->val);
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

    TreeNode *findTarget(TreeNode *root, int target)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->val == target)
        {
            return root;
        }

        TreeNode *leftResult = findTarget(root->left, target);
        if (leftResult)
        {
            return leftResult;
        }

        TreeNode *rightResult = findTarget(root->right, target);
        if (rightResult)
        {
            return rightResult;
        }
        else
        {
            return NULL;
        }
    }
};

int main()
{
    int n, target, k;
    cin >> n >> target >> k;
    vector<string> vec(n);
    for (string &x : vec)
    {
        cin >> x;
    }
    Solution sol;
    TreeNode *root = sol.createBinaryTree(vec);
    TreeNode *targetNode = sol.findTarget(root, target);
    vector<int> ans = sol.distanceK(root, targetNode, k);
    for (int &it : ans)
    {
        cout << it << " ";
    }
}