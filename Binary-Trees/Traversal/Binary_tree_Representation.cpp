#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

class Solution
{
public:
    void create_tree(node *root0, vector<int> &vec) // simple enough
    {
        // TC: O(1), O(1)
        node* temp=root0;
        temp->left=newNode(vec[1]);
        temp->right=newNode(vec[2]);
        temp=root0->left;
        temp->left=newNode(vec[3]);
        temp->right=newNode(vec[4]);
        temp=root0->right;
        temp->left=newNode(vec[5]);
        temp->right=newNode(vec[6]);
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
    node *root0 = newNode(vec[0]);
    Solution sol;
    sol.create_tree(root0, vec);
    return 0;
}
