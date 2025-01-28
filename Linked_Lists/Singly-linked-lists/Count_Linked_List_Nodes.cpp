#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    int getCount(Node *head)
    {
        int count = 0;
        Node *current = head;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    Node *constructLL(vector<int> &vec)
    {
        if (vec.empty())
        {
            return NULL;
        }
        Node *head = new Node(vec[0]);
        Node *current = head;
        for (int i = 1; i < vec.size(); i++)
        {
            Node *newNode = new Node(vec[i]);
            current->next = newNode;
            current = current->next;
        }
        return head;
    }

    void printLL(Node *head)
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    Solution sol;
    Node *head = sol.constructLL(vec);
    // sol.printLL(head);
    int ans = sol.getCount(head);
    cout << ans << endl;

    return 0;
}