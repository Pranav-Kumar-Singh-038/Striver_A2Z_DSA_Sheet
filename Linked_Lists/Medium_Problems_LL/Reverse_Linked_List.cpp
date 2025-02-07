#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

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
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution
{
public:
    Node *reverseList(Node *head) // Iterative
    // TC: O(n) SC: O(1)
    {
        if (head == NULL)
        {
            return head;
        }
        Node *current = head;
        Node *prev = NULL;
        while (current->next != NULL)
        {
            Node *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        current->next = prev;
        return current;
    }

    Node *reverseList2(Node *head,  Node *prev = NULL) // Recursive
    // TC: O(n) SC: O(n) (recursive call stack)
    {
        if (head == NULL)
        {
           return prev;
        }

        Node *nextNode = head->next; 
        head->next = prev;
        Node* ans=reverseList2( nextNode, head);
        return ans;
    }

    void printLL(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    Node *constructLL(vector<int> vec)
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
    Node *newHead = sol.reverseList2(head);
    sol.printLL(newHead);
}