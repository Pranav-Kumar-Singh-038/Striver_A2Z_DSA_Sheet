#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    void allTraversals(vector<int> &inVec, vector<int> &preVec, vector<int> &postVec, Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        preVec.push_back(root->val);
        allTraversals(inVec, preVec, postVec, root->left);
        inVec.push_back(root->val);
        allTraversals(inVec, preVec, postVec, root->right);
        postVec.push_back(root->val);
        return;
    }

    vector<vector<int>> prePostInTraversal(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> inVec, preVec, postVec;
        allTraversals(inVec, preVec, postVec, root);
        ans = {preVec, postVec, inVec};
        return ans;
    }

    Node *createBT(vector<string> vec)
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
            int val;
            Node *node = q.front();
            q.pop();
            if (i < vec.size() && vec[i] != "null")
            {
                val = stoi(vec[i]);
                node->left = new Node(val);
                q.push(node->left);
            }
            i++;
            if (i < vec.size() && vec[i] != "null")
            {
                val = stoi(vec[i]);
                node->right = new Node(val);
                q.push(node->right);
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
    for (string &it : vec)
    {
        cin >> it;
    }
    Solution sol;
    Node *root = sol.createBT(vec);
    vector<vector<int>> ans = sol.prePostInTraversal(root);
    cout << "Pre Order: ";
    for (int &it : ans[0])
    {
        cout << it << " ";
    }
    cout<<endl;
    cout << "Post Order: ";
    for (int &it : ans[1])
    {
        cout << it << " ";
    }
    cout<<endl;
    cout << "In Order: ";
    for (int &it : ans[2])
    {
        cout << it << " ";
    }
    cout<<endl;
}