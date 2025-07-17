#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
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
    void bottomViewHelper(Node *root, vector<int> &vec, vector<int> &priorityVec, int horizontalDistance, int priority, int mid)
    {
        // TC:O(n), SC:O(n) (call stack)
        if (root == NULL)
        {
            return;
        }
        if (vec[mid + horizontalDistance] == INT_MIN)
        {
            vec[mid + horizontalDistance] = root->data;
            priorityVec[mid + horizontalDistance] = priority;
        }
        else if (priorityVec[mid + horizontalDistance] <= priority)
        {
            vec[mid + horizontalDistance] = root->data;
            priorityVec[mid + horizontalDistance] = priority;
        }
        bottomViewHelper(root->left, vec, priorityVec, horizontalDistance - 1, priority + 1, mid);
        bottomViewHelper(root->right, vec, priorityVec, horizontalDistance + 1, priority + 1, mid);
    }

    int countNodes(Node *root)
    {
        // TC:O(n), SC:O(n) (worst case)
        if (root == NULL)
        {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    vector<int> bottomView(Node *root)
    {
        // TC:O(4n+1)=(n), SC:O(7n+1)=O(n)
        // The idea is we do a recursive(dfs) approach, this causes deeper nodes to be
        // accessed first which is a problem, as nodes in the right branch will be visited
        // later and may be assigned, to avoid this we keep a priority(depth) vec and a answer vec
        // if we visit a node and its the first time, we store its value in answer vec and priority
        // in priority vec which is its depth, if not, we check its priority from the priority vec
        // if it is smaller from our current priority we update the values, this causes only
        // the deepest nodes to be stored,
        // to store the nodes in a vector we access them by mid+horizontal distance, and mid
        // whose value is n, prevents accessing negative nodes, we make the priority and ans
        // vectors to be 2n+1 size because it may be that the tree is skewed to the right
        // adding +n to horizontal causes the node at n hd to move to 2n
        // we find the number of nodes by dfs based counting of left and right nodes+1 for the current node
        vector<int> answer; // SC:O(n)
        int n = countNodes(root);  // TC:O(n), SC:O(n)
        vector<int> vec(2 * n + 1, INT_MIN); // SC:O(2n+1)
        vector<int> priorityVec(2 * n + 1, INT_MIN);// SC:O(2n+1)
        int mid = n, horizontalDistance = 0, priority = 0;
        int leftIndex = 0, rightIndex = 0;

        bottomViewHelper(root, vec, priorityVec, horizontalDistance, priority, mid); // TC:O(n), SC:O(n)
        for (int a : vec) // TC:O(2n+1)
        {
            if (a != INT_MIN)
            {
                answer.push_back(a);
            }
        }

        return answer;
    }

    vector<int> bottomView1(Node *root)
    {
        // The idea is that root node has horizontal distance hd=0, its left node has
        // -1 and right has +1, similarly all nodes have horizontal distance, we traverse
        // in level order, and push every Hd into the map, this causes the hd's pushed later
        // to remain in the map, and later hd'd are what visible from the bottom.
        // we use a map for this to store in the order of the horizontal distance, which 
        // is from left to right. i.e smallest to largest
        // Suboptimal        
        // TC:O(nlogn+n)= O(nlogn), SC:O(3n)= O(n)
        vector<int> vec; // SC:O(n)
        if (root == NULL)
        {
            return vec;
        }
        queue<pair<Node *, int>> q; // SC:O(n)
        map<int, int> myMap;        // SC:O(n/2)
        q.push({root, 0});
        while (!q.empty()) // TC:O(n)
        {
            Node *node = q.front().first;
            int HD = q.front().second;
            q.pop();
            myMap[HD] = node->data; // TC:O(logn)
            if (node->left)
            {
                q.push({node->left, HD - 1});
            }
            if (node->right)
            {
                q.push({node->right, HD + 1});
            }
        }
        for (auto it : myMap) // TC:O(n)
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
    vector<int> ans = sol.bottomView(root);
    for (auto &val : ans)
    {
        cout << val << " ";
    }
    return 0;
}