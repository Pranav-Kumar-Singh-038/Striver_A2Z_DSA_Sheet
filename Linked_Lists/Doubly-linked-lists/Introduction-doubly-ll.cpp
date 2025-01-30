#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *constructDLL(vector<int> &vec)
    {
        if (vec.empty())
            return NULL;
        Node *head = new Node(vec[0]);
        Node *current = head;
        Node *previous = NULL;
        for (int i = 1; i < vec.size(); i++)
        {
            Node *newNode = new Node(vec[i]);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        return head;
    }

    void printDLL(Node *head)
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
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
    Node *head = sol.constructDLL(vec);
    sol.printDLL(head);
}
