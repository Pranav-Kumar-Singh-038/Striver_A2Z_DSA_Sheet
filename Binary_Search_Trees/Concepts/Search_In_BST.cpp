#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int val)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = val;
    }
};

class Solution
{
public:
    Node *searchBST(Node *root, int val) // if root is smaller move right, else left, if root is equal to value return.
    {
        // TC: O(logn)(if not skewed), SC: O(1)
        Node* current=root;
        while(current!= NULL)
        {
            if(current->data==val)
            {
                return current;
            }
            else if(current->data > val)
            {
                current=current->left;
            }
            else
            {
                current=current->right;
            }
        }
        return NULL;
    }

    Node *createBST(vector<optional<int>> vec)
    {
        if (vec.empty() || !vec[0].has_value())
        {
            return NULL;
        }
        Node *root = new Node(vec[0].value());
        Node *current=NULL;
        queue<Node *> q;
        q.push(root);
        int i = 1;
        while (i < vec.size())
        {
            current = q.front();
            q.pop();
            if (i < vec.size() && vec[i].has_value())
            {
                current->left = new Node(vec[i].value());
                q.push(current->left);
            }
            i++;
            if (i < vec.size() && vec[i].has_value())
            {
                current->right = new Node(vec[i].value());
                q.push(current->right);
            }
            i++;
        }
        return root;
    }
    
    void printBT(Node* root)
    {
        Node* current;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            current=q.front();
            q.pop();
            if(current->left)
            {
                q.push(current->left);
            }
            if(current->right)
            {
                q.push(current->right);
            }
            cout<<current->data<<" ";
        }
    }

};

int main()
{
    int n, val;
    cin >> n >> val;
    vector<optional<int>> vec(n);
    string x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == "null")
        {
            vec[i] = nullopt;
        }
        else
        {
            vec[i] = stoi(x);
        }
    }
    Solution sol;
    Node *root = sol.createBST(vec);
    Node *ans = sol.searchBST(root, val);
    if(ans==NULL)
    {
        cout<<"";
    }
    else
    {
       sol.printBT(ans);
    }
    return 0;
}