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
    int minValue(Node *root) // The leftmost node is the smallest
    {
        // TC: O(logn), O(n) Worst, SC: O(1)
        if(root==NULL)
        {
            return -1;
        }
        Node* current=root;
        while(current->left)
        {
            current=current->left;
        }
        return current->data;
    }

    Node *createBST(vector<optional<int>> vec)
    {
        if (vec.empty() || !vec[0].has_value())
        {
            return NULL;
        }
        Node *root = new Node(vec[0].value());
        Node *current = NULL;
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
        if(root==NULL)
        {
            cout<<"";
            return;
        }
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
    int n;
    cin >> n;
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
    int ans = sol.minValue(root);
    cout<<ans;
    return 0;
}