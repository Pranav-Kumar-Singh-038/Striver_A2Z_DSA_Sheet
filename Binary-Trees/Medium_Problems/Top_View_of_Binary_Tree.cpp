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
    vector<int> topView(Node *root)
    {
        // The idea is that root node has horizontal distance hd=0, its left node has
        // -1 and right has +1, similarly all nodes have horizontal distance, we traverse
        // in level order, and push every first appearance of a horizontal distance, 
        // because only the left most and right most will have new horizontal distances
        // we use a map for this to store in the order of the horizontal distance, which 
        // is from left to right. i.e smallest to largest

        // TC:O(n+nlogn), SC:O(3n)
        vector<int> vec; // SC:O(n)
        if (root == NULL)
            {return vec;}

        map<int, int> topNode;  // SC:O(n)
        queue<pair<Node *, int>> q; // SC:O(n)

        q.push({root, 0});

        while (!q.empty()) // TC:O(n)
        {
            auto p = q.front();
            q.pop();
            Node *node = p.first;
            int hd = p.second;

            if (topNode.find(hd) == topNode.end()) // TC:O(logn)
            {
                topNode[hd] = node->val;
            }

            if (node->left)
            {
                q.push({node->left, hd - 1});
            }
            if (node->right)
            {
                q.push({node->right, hd + 1});
            }
        }

        for (auto it : topNode) // TC:O(n)
        {
            vec.push_back(it.second);
        }

        return vec;
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
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    Solution sol;
    Node *root = sol.createBinaryTree(vec);
    vector<int> ans = sol.topView(root);
    for (auto &val : ans)
    {
        cout << val << " ";
    }
    return 0;
}