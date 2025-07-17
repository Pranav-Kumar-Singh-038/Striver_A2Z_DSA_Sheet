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
    vector<vector<int>> zigzagLevelOrder(Node *root)
    {
        // simply do bfs with a toggle, when that toggle is active, access the vector
        // from back, else do from front, define the size of the vector beforehand for this

        // another method is to reverse the vector at each toggle, but it will cause time
        // overhead for reverse

        // another method is use deque, simple do push_back if no toggle, else do push_front
        // but it will cause space overhead for deque
        
        // TC:O(n), SC:O(3n)=O(n)
        vector<vector<int>> ans; // SC:O(n)
        if (root == NULL)
        {
            return ans;
        }
        queue<Node *> q; // SC:O(n/2)
        q.push(root);
        bool toggle = false;
        while (!q.empty()) // TC:O(n)
        {
            int size = q.size();
            vector<int> level(size); // SC:O(n/2)
            for (int i = 0; i < size; i++) // TC:O(n/2)
            {
                Node *node = q.front();
                q.pop();
                int index = (!toggle) ? i : (size - 1 - i);

                level[index] = node->val;
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(level);
            toggle = !toggle;
        }
        return ans;
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
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);
    for (auto &val : ans)
    {
        for (auto &it : val)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}