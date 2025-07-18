#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


class Solution
{
public:
    int isSumProperty(Node *root) {
        // The idea is we do a bfs and for each node we check if its children sum is equal
        // to its value if yes move on, if no return 0. Remember to check for leaf nodes as they 
        // are to be skipped
        // TC:O(n), SC:O(n)
       if(root==NULL)
       {
        return 1;
       }
       queue<Node*> q; // SC:O(n)
       q.push(root);
       while(!q.empty()) // TC:O(n)(amortized)
       {
        int size=q.size();
        for(int i=0;i<size;i++) 
        {
            int childrenSum=0;
            Node* current=q.front();
            q.pop();
            if(current->left)
            {
                q.push(current->left);
                childrenSum+=current->left->data;
            }
            if(current->right)
            {
                q.push(current->right);
                childrenSum+=current->right->data;
            }
            if(!current->left && !current->right)
            {
                childrenSum=current->data;
            }
            // cout<<childrenSum<<endl;
            if(childrenSum!=current->data)
            {
               return 0;
            }
        }
       }
       return 1;
    }

    Node *createBinaryTree(const vector<string> &vec)
    {
        if (vec.empty() || vec[0] == "null")
        {
            return NULL; 
        }

        Node *root = new Node(stoi(vec[0]));
        queue<Node *> q;
        q.push(root);
        int i = 1;

        while (i < vec.size())
        {
            Node *current = q.front();
            q.pop();

            if (i < vec.size() && vec[i] != "null")
            {
                current->left = new Node(stoi(vec[i]));
                q.push(current->left);
            }
            i++;

            if (i < vec.size() && vec[i] != "null")
            {
                current->right = new Node(stoi(vec[i]));
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
    Node *root = sol.createBinaryTree(vec);
    int ans = sol.isSumProperty(root);
    cout<<ans;
}